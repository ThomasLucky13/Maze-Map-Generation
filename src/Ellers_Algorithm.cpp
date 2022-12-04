#include "Ellers_Algorithm.h"
#include<cstdlib>
#include <ctime>

// ---------------- Инициализация клеток ---------------- //
            void Ellers_Algorithm::Init(int _width, int _height)
            {
                // --- Проверка ширины лабиринта --- //
                if (_width>0)
                {
                    width = _width;
                } else width = 1;

                // --- Проверка длины лабиринта --- //
                if (_height>0)
                {
                    height = _height;
                } else height = 1;

                // --- Обновление лабиринта --- //
                cells = std::vector<std::vector<Cell>>();// новые параметры

                for (int i = 0; i< height; i++) // по строкам
                {
                    cells.push_back(std::vector<Cell>());
                    for (int j = 0; j < width; ++j) // по столбцам
                    {
                        cells[i].push_back(Cell()); // инициализация клетки
                    }
                }

                // --- Обновление множеств --- //
                void_multiplicities = 1;

                // --- Установка проверочных флагов --- //
                outside_wall_right = false;
                outside_wall_bottom = false;
            }
        //--------------------------------------------------------//

        // -------------------- Конструкторы -------------------- //
            Ellers_Algorithm::Ellers_Algorithm()
            {
                Init(1,1);
            }

            Ellers_Algorithm::Ellers_Algorithm( int _height, int _width)
            {
                Init(_width, _height);
            }
        //--------------------------------------------------------//

        // ----------------- Генерация лабиринта ---------------- //
            // ---- Присвоение множества из хранилища ---- //
            void Ellers_Algorithm::Set_New_Multiplicity(int i, int j)
            {
                cells[i][j].set_multiplicity(void_multiplicities);
                void_multiplicities++;
            }

            // ---- Присвоение определенного множества ---- //
            void Ellers_Algorithm::Set_Multiplicity(int i, int j, uint _multiplicity)
            {
                cells[i][j].set_multiplicity(_multiplicity); // присваеваем новое множество
            }

            void Ellers_Algorithm::Generate_RightWalls(int i)
            {
                ///
                ///Проходим по клеткам в строке.
                ///Если клетка справа принадлежить другому множеству,
                ///то смотрим, добавлять ли стенку.
                /// Если стенка не добавляется,
                ///то клетке справа присваиваем то же множество,
                /// что и у текущей
                ///Если клетка справа того же множества,
                ///то добавляем стенку
                ///
                for (int j = 0; j <width-1; j++)
                {
                    // --- Проверяем на несовпадение множества у клеток --- //
                    // --- Если не совпадает множество --- ///
                    if (cells[i][j].Multiplicity()!=cells[i][j+1].Multiplicity())
                    {
                        x = rand()%2; // если 0 - то ставим, если 1 - то не ставим

                       // --- Ставим стенку справа --- //
                        if (x==0)
                        {
                            cells[i][j].Put_RightWall();
                        } else if (x==1)
                        // --- Не ставим стенку справа --- //
                        {
                            Set_Multiplicity(i, j+1, cells[i][j].Multiplicity());
                        }
                    } else
                    // --- Если совпадает множество --- //
                    {
                        cells[i][j].Put_RightWall(); //ставим стенку справа
                    }
                }
            }

            void Ellers_Algorithm::Generate_BottomWalls(int i)
            {
                ///
                /// Проходим по клеткам вправо
                /// Добавляем нижнюю стенку
                /// В одном множестве должна быть хотя бы одна клетка без нижней стенки
                ///
                check = false;
                for (int j=0; j < width-1; j++)
                {
                    // --- Есои след.клетка другого множества --- //
                    if (cells[i][j].Multiplicity()!=cells[i][j+1].Multiplicity())
                    {
                        if (check)
                        {
                            x = rand()%2; // если 0 - добавляем, если 1 - то нет
                            if (x==0) cells[i][j].Put_BottomWall();
                            check = false;
                        }

                    } else
                    // --- Если след. клетка того же множества --- //
                    {
                        x = rand()%2; // если 0 - добавлем, если 1 - то нет
                        if (x==0)
                        {
                            cells[i][j].Put_BottomWall();
                        } else
                        {
                            check = true;
                        }
                    }
                }

                if (check)
                {
                    x = rand()%2; // если 0 - добавляем, если 1 - то нет
                    if (x==0) cells[i] [width-1].Put_BottomWall();
                    check = false;
                }

            }

            void Ellers_Algorithm::Generate_OutsideBottomWalls()
            {
                int i = height - 1;
                for (int j = 0; j<width; j++)
                {
                    if ((j!=width-1)||(outside_wall_bottom))
                    {
                        x = rand()%2; // если 0 - то ставим, если 1 - то не ставим

                        // --- Ставим стенку cнизу --- //
                        if (x==0)
                        {
                            cells[i][j].Put_BottomWall();
                        } else if (x==1)
                        // --- Не ставим стенку справа --- //
                        {
                            outside_wall_bottom = true;
                        }
                    }
                }
            }

            void Ellers_Algorithm::Copy_Line(int i, int ii)
            {
                ///
                ///Копируем в нижнюю линюю верхнюю
                ///Удаляем все правые стенки
                ///Если есть нижняя стенка, то убираем из множества
                ///
                for (int j = 0; j < width; j++)
                {
                    if(cells[i][j].BottomWall()) cells[ii][j].set_multiplicity(0);
                    else cells[ii] [j].set_multiplicity(cells[i][j].Multiplicity());
                }
            }

            void Ellers_Algorithm::Remove_AllRightWalls(int i)
            {
                for (int j = 0; j<width; j++)
                    cells[i][j].Remove_RightWall();
            }

            void Ellers_Algorithm::Generate(int _height, int _width)
            {
                Init(_width, _height); //инициализируем новый лабиринт

                for (int i = 0; i<height; i++)
                {
                    ///
                    /// Если клетка не принадлежит множеству,
                    ///то присваиваем ей новое множенство
                    ///
                    for (int j = 0; j < width; j++)
                    {
                        if(cells[i][j].Multiplicity()==0) Set_New_Multiplicity(i,j);

                    }

                    Generate_RightWalls(i);
                    Generate_BottomWalls(i);

                    // Если не последняя строка
                    if (i!=height-1)
                    {
                        Copy_Line(i, i+1);
                    }


                }
               // Generate_OutsideBottomWalls();
            }
        //--------------------------------------------------------//

        // ---------------- Возвращение лабиринта ---------------- //
            std::vector<std::vector<Cell>> Ellers_Algorithm::Maze()
            {
                return cells;
            }
        //--------------------------------------------------------//
