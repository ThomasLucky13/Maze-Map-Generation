#ifndef ELLERS_ALGORITHM_H
#define ELLERS_ALGORITHM_H

#include <vector>
#include "Cell.h"

class Ellers_Algorithm
{
    public:
        Ellers_Algorithm();
        Ellers_Algorithm(int _height, int _width);
        void Generate(int _height = 1, int _width = 1);
        std::vector<std::vector<Cell>> Maze();

    protected:

    private:
        int width, height;                    // --- Ширина и высота лабиринта в кол-ве клеток --- //
        std::vector<std::vector<Cell>> cells;      // --------------- Клетки лабиринта ---------------- //
        unsigned int void_multiplicities;     // -------------- свободное множество -------------- //
        bool check = false;                           // для проверки при добавлении нижних стенок
        int x;                                        // для хранения результатов генерации
        bool outside_wall_right, outside_wall_bottom; // для проверки при добавлении крайних стенок
        void Init(int _width, int _height);
        void Set_New_Multiplicity(int i, int j);
        void Set_Multiplicity(int i, int j, unsigned int _multiplicity);
        void Generate_RightWalls(int i);
        void Generate_BottomWalls(int i);
        void Generate_OutsideBottomWalls();
        void Copy_Line(int i, int ii);
        void Remove_AllRightWalls(int i);
};

#endif // ELLERS_ALGORITHM_H
