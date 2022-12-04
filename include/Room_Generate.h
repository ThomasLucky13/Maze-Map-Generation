#ifndef ROOM_GENERATE_H
#define ROOM_GENERATE_H

#include "Room.h"
#include "Map_Splitting.h"
#include <vector>
#include<cstdlib>


class Room_Generate
{
    public:
        static std::vector<Room> Generate_Rooms(std::vector<std::vector<split_leaf>> leaves, int min_room, int mid_room, int max_room, int map_height, int map_width, int min_distance);
    protected:

    private:
        static Room GenerateRoom(int x_start, int x_end, int y_start, int y_end, int width);
        static int Find_center_second(std::vector<split_leaf> leaves);
        static int Find_center_third(std::vector<split_leaf> leaves);
        static int random(int minimum, int maximum)
        {
            if ((maximum+1 - minimum)==0)
            {
                return minimum;
            }
            return rand()%(maximum+1 - minimum)+ minimum;
        }

};

#endif // ROOM_GENERATE_H
