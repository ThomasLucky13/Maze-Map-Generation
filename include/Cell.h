#ifndef CELL_H
#define CELL_H

class Cell
{

    public:
        Cell();

        bool RightWall();
        void Put_RightWall();
        void Remove_RightWall();
        void Display_RightWall();

        bool BottomWall();
        void Put_BottomWall();
        void Remove_BottomWall();
        void Display_BottomWall();

        unsigned int Multiplicity();
        void set_multiplicity(unsigned int _multiplicity);

        void Use();
        bool isUnused();

    private:

        bool right_wall;    // ------------ Правая стенка ------------ //
        bool bottom_wall;    // ----------- Верхняя стенка ----------- //
        unsigned int multiplicity;              // --- Множество к которому принадлежит клетка --- //
        bool unused;
};

#endif // CELL_H
