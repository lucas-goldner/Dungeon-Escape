#include "helpers.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#if __unix__ || __APPLE__
#include <termios.h>
#include <unistd.h>

static struct termios new_io;
static struct termios old_io;

static int cbreak(int fd)
{
    if ((tcgetattr(fd, &old_io)) == -1)
        return -1;
    new_io = old_io;
    new_io.c_lflag = new_io.c_lflag & ~(ECHO | ICANON);
    new_io.c_cc[VMIN] = 1;
    new_io.c_cc[VTIME] = 0;

    if ((tcsetattr(fd, TCSAFLUSH, &new_io)) == -1)
        return -1;
    return 1;
}

int getCharacter(void)
{
    int c;

    if (cbreak(STDIN_FILENO) == -1)
    {
        printf("Error in function cbreak ... \n");
        exit(EXIT_FAILURE);
    }
    c = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &old_io);
    return c;
}

void clearScreen()
{
    std::cout << "\x1b[2J";
}

#elif __WIN32__ || _WIN32 || _MSC_VER || __MS_DOS__
#include <conio.h>

void clearScreen()
{
    system("cls");
}

int getCharacter(void)
{
    return _getch();
}
#endif
