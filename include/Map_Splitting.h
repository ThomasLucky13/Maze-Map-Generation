#ifndef MAP_SPLITTING_H
#define MAP_SPLITTING_H

#include <vector>
#include<cstdlib>

 // ---------------- Структура лист - который используется для разбиения карты -------------- //
    struct split_leaf
    {
    public:
        int i, j; // начальные координаты листа на карте
        int height, width; //размер листа

        split_leaf(int _i, int _j, int _height, int _width)
        {
            i = _i; j = _j;
            height = _height; width = _width;
        }
        split_leaf()
        {
            i = 0; j = 0;
            height = 0; width = 0;
        }
    };
    //-------------------------------------------------------------------------------------------//

class Map_Splitter
{
    public:
        static std::vector<split_leaf> Reverse_Split(std::vector<split_leaf> leaves, int height, int width);
        static std::vector<split_leaf> Split(int map_height, int map_width, int min_height, int min_width);
    protected:

    private:
        static std::vector<split_leaf> VerticalSplit(std::vector<split_leaf> leaves, int min_width);
        static std::vector<split_leaf> HorizontalSplit(std::vector<split_leaf> leaves, int min_height);
        static int random(int minimum, int maximum)
        {
            if ((maximum+1 - minimum)==0)
            {
                return minimum;
            }
            return rand()%(maximum+1 - minimum)+ minimum;
        }
};

#endif // MAP_SPLITTING_H
