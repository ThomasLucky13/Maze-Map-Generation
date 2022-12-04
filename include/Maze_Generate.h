#ifndef MAZE_GENERATE_H
#define MAZE_GENERATE_H
#include "Ellers_Algorithm.h"
#include "Room_Generate.h"
#include<cstdlib>
#include <ctime>
#include <vector>

class Maze_Generate
{
    public:
        static std::vector<Room> Get_rooms(int height, int width, int min_room, int mid_room, int max_room, int distance);
        static std::vector<std::vector<Cell>> Get_map(int height, int width, std::vector<Room> rooms);

    protected:

    private:
        static void Set_Room( std::vector<std::vector<Cell>>& maze_map, Room room);

};

#endif // MAZE_GENERATE_H
