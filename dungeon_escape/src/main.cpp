#include "helpers.hpp"
#include "dungeon.hpp"
#include <iostream>
#include <helpers.hpp>
using namespace std;

Dungeon d = Dungeon();

enum Inputs
{
    INPUT_W = 87,
    INPUT_A = 65,
    INPUT_S = 83,
    INPUT_D = 68,
};

bool handleInput(int input)
{
    switch (input)
    {
    case INPUT_W:
        d.moveToPosition(d.position.x, d.position.y - 1);
        break;
    case INPUT_A:
        d.moveToPosition(d.position.x - 1, d.position.y);
        break;
    case INPUT_S:
        d.moveToPosition(d.position.x, d.position.y + 1);
        break;
    case INPUT_D:
        d.moveToPosition(d.position.x + 1, d.position.y);
        break;

    default:
        break;
    }

    clearScreen();
    d.draw();

    if (d.position.y == 4 && d.position.x == 5)
    {
        cout << "You found the exit. Congratulations!\n";
        return true;
    }
    return false;
}

int main(int argc, char *argv[])
{
    cout << "Try to escape the dungeon, use 'W' (up), 'A' (left), 'S' (down), and 'D' (right) to move around. \n";

    bool foundExit = false;
    d.draw();
    while (foundExit != true)
    {
        foundExit = handleInput(getCharacter());
    }

    return 0;
}