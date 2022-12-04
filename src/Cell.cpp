#include "Cell.h"
#include <iostream>
Cell::Cell()
{
    right_wall = false;
    bottom_wall = false;
    unused = true;
    multiplicity = 0;
}

// ---------------- Правая стенка --------------- //

// ----- Получение значения ----- //
bool Cell::RightWall()
{
    return right_wall;
}

// ------ Поставить стенку ------ //
void Cell::Put_RightWall()
{
    right_wall = true;
}

// -------- Убрать стенку ------- //
void Cell::Remove_RightWall()
{
    right_wall = false;
}

// --------- Вывод стенки ------- //
void Cell::Display_RightWall()
{
    if (right_wall)
        std::cout << " |";
    else std::cout << "  ";
}

//------------------------------------------------//

// ---------------- Нижняя стенка --------------- //

// ----- Получение значения ----- //
bool Cell::BottomWall()
{
    return bottom_wall;
}

// ------ Поставить стенку ------ //
void Cell::Put_BottomWall()
{
    bottom_wall = true;
}

// -------- Убрать стенку ------- //
void Cell::Remove_BottomWall()
{
    bottom_wall = false;
}

// --------- Вывод стенки ------- //
void Cell::Display_BottomWall()
{
    if (bottom_wall)
        std::cout << "__";
    else
        std::cout << "  ";
}
//------------------------------------------------//

// ----------------- Множество ------------------ //
// ---- Получение множества ---- //
unsigned int Cell::Multiplicity()
{
    return multiplicity;
}

// ---- Установить множество --- //
void Cell::set_multiplicity(unsigned int _multiplicity)
{
    if (_multiplicity >= 0) multiplicity = _multiplicity;
}
//------------------------------------------------//

void Cell::Use()
{
    unused = false;
}

bool Cell::isUnused()
{
    return unused;
}
