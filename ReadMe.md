# Exercise: Dungeon Escape

This exercise was part of the advanced programming course c++ that I took at university. I wanted to include it
on github, since this is the first larger c++ program that I made.

## Introduction

In this excercise you will implement a simple maze game called Dungeon Escape. The game is a console game. The player is trapped in a maze and has to escape. The goal is to find the exit of the dungeon. For this exercise, you will implement input and output and basic game mechanics.

A project is already setup for you in the `dungeon_escape` folder. We will first implement a basic Vector2D class to store the player position. There are unit tests available which help you implement this class. Then, we will implement the actual dungeon and the player.

## Vector2D

The project contains tests for a Vector2D class which you can activate to check your solution. You will have to implement the class from scratch and make all unit tests pass.:

1. Add a `vector2d.hpp` file to the `dungeon_escape/include` directory and a `vector2d.cpp` file to the `dungeon_escape/src` directory.
2. Add include guards to the header file and include it in the cpp file.
3. Add the source file to the CMake project by appending it to `SOURCES` in the `CMakeLists.txt` file.
4. Activate the unit test `test/vector2d.cpp` by removing the `#` character in the `CMakeLists.txt` file. If you run the tests, they should now fail.
5. Declare the `class` or `struct` called `Vector2D` in the header file and implement its methods and operators to the cpp file.
6. Add integer members for `x` and `y`.
7. Implement component-wise arithmetic operators for `+`, `-`, and `*`.
8. Add operators for arithmetic with scalar values: e.g. `Vector2D res = 5 + v`.
9. Also implement assignment versions of these operators.
   You can check what is missing by running the unit tests. Look at the compiler output if they fail to compile. Otherwise a test report will be output.

## Dungeon Escape

Now that we have a class for handling player position, we can use it to implement the game. We will start with some output, the game loop and character based input.

1. When the program is started, show a message with playing instructions, e.g. `Try to escape the dungeon, use 'W' (up), 'A' (left), 'S' (down), and 'D' (right) to move around.`.
2. Add a loop to the `main.cpp` file which handles user input and generates output.
3. We wand to read user input one character at a time, so the user does not have to press `Return` after each movement command. Sadly, standard C++ does only provide us with line based input. To circumvent this limitation, we will use a helper function, called `getCharacter()` which is included in the `helpers.hpp` file. The function blocks until a character is typed in and returns the character as an int.
4. Add a dummy function for output which is called in the loop after input. You should now see the output being printed each time you press a character on the keyboard.
5. Implement a class `Dungeon` which contains the current level and the player position. For the player position use the `Vector2D` class from before. The player should start at position `{1, 1}`.
6. The easiest solution to store the level is a vector of strings with each string containing one row of the level. You can do this with `std::vector<std::string>`.
7. Initialize a level in the parameterless `constructor` of the `Dungeon` class. In C++ it is a special member function named as the class and without a return type, e.g. `Dungeon()`. You can use the following syntax:
   ```cpp
   level = {
       "######",
       "#    #",
       "# ## #",
       "#  ###",
       "#    O",
       "######"
   }
   ```
   Where `#` depicts a wall and `O` the exit.
8. Create a either a global instance of the Dungeon class or a local one in the main function above the loop.
9. Implement a member function called `draw` which outputs the whole level including the player. The player should be drawn with an `X` instead of the character in the level. Instead of the dummy output function above, call `Dungeon::draw` after each input.
10. We now need to move the player around when one of the four movement buttons is pressed. Implement a member function for each direction the player can move. When trying to move, stay on the current location if a wall will be hit, else move the player. If the player reaches the exit, the game is finished. Return either a boolean value from the draw function in case the game is finished or set a state which can be checked from the main loop.
11. Call the respective movement function after a character is input.
12. Exit the main loop and show a congratulations message when the player escaped the maze.
13. The game is really easy as the user can see the complete level. Now, we want to display only a 5x5 area around the player in the draw function. Hint: When implementing check for boundary conditions, e.g. the player is in the upper-left corner of the level. The `min` and `max` functions in the `<algorithm>` could help.
14. There is one issue left to solve: The new dungeon is drawn below the last one when the player presses a movement button. We have to clear the screen after each input. As with the character based input, there is no standard way to do this. So a helper function is provided in `helpers.hpp` called `clearScreen()`.
