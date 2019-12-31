#ifndef DATA_H
#define DATA_H
#include <SFML/Graphics.hpp>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <assert.h>
#include <math.h>

#if defined(_WIN32)
#include <Windows.h>
#elif defined(__linux__)
#include <unistd.h>
#define Sleep(m) usleep(m * 1000)
#endif

enum Direction {
    Still = 0, Up, Down, Left, Right
};

using namespace sf;

#endif