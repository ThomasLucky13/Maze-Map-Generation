#include "Room.h"



        // ---------------- Инициализация клеток ---------------- //
            void Room::Init(int _height, int _width)
            {
                // --- Проверка ширины комнаты //
                    if (_width>0)
                    {
                        width = _width;
                    } else width = 0;

                // --- Проверка длины комнаты --- //
                    if (_height>0)
                    {
                        height = _height;
                    } else height = 0;

                x = 0; y = 0;  // Начальные координаты
            }
        //------------------------------------------------//

        // ---------------- Конструкторы ---------------- //
            Room::Room()
            {
                Init(0,0);
            }

            Room::Room(int _height, int _width)
            {
                Init(_height,_width);
            }
            Room::Room(int _height, int _width, int _x, int _y)
            {
                Init(_height,_width);
                x = _x;
                y = _y;
            }
        //------------------------------------------------//

        // ------------- Координаты комнаты ------------- //
            int Room::X()
            {
                return x;
            }

            void Room::set_x(int _x)
            {
                x = _x;
            }

            int Room::Y()
            {
                return y;
            }

            void Room::set_y(int _y)
            {
                y = _y;
            }
        //------------------------------------------------//

        // ------------- Параметры комнаты -------------- //
            int Room::Width()
            {
                return width;
            }

            int Room::Height()
            {
                return height;
            }
        //------------------------------------------------//
