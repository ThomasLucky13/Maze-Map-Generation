#ifndef ROOM_H
#define ROOM_H

#include "Cell.h"

class Room
{
    public:
        Room();
        Room(int _height, int _width);
        Room(int _height, int _width, int _x, int _y);

        int X();
        void set_x(int _x);
        int Y();
        void set_y(int _y);

        int Width();
        int Height();
    protected:

    private:
        int x, y;          // Координаты команты
        int width, height; // Размер команты

        void Init(int _height, int _width);
};

#endif // ROOM_H
