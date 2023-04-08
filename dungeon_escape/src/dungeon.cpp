#include <dungeon.hpp>
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int VIEW_DISTANCE_MAX = 5;

Dungeon::Dungeon()
{
    position = {1, 1};
    level = {
        "######",
        "#    #",
        "# ## #",
        "#  ###",
        "#    O",
        "######"};
}

Dungeon::~Dungeon()
{
}

void Dungeon::draw()
{

    for (int i = 0; i <= level.size() - 1; i++)
    {
        int leftBound = max(position.x - VIEW_DISTANCE_MAX / 2, 0);
        int rightBound = min(VIEW_DISTANCE_MAX, (int)level[i].length() - leftBound);
        int upperBound = max(4 - position.y + i, 0);
        int lowerBound = min(VIEW_DISTANCE_MAX - 1 - (position.y - i), VIEW_DISTANCE_MAX);
        string level_layer = level[i].substr(leftBound, rightBound);

        if (upperBound <= lowerBound)
        {
            if (position.y == i)
            {
                string level_section_with_player = level_layer;
                level_section_with_player[position.x - leftBound] = 'X';
                cout << level_section_with_player + "\n";
            }
            else
            {

                cout << level_layer + "\n";
            }
        }
    }
}

void Dungeon::moveToPosition(int x, int y)
{
    if (level[y][x] == '#')
    {
        return;
    }

    position.x = x;
    position.y = y;
}