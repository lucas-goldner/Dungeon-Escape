#pragma once
#include "vector2d.hpp"
#include <vector>
#include <string>
using namespace std;

class Dungeon
{
public:
    Vector2D position;
    vector<string> level;
    Dungeon();
    ~Dungeon();
    void draw();
    void moveToPosition(int x, int y);
};
