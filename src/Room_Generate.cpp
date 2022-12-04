#include "Room_Generate.h"
// ------------------------------ Генерируем новую комнату ---------------------------- //
        Room Room_Generate::GenerateRoom(int x_start, int x_end, int y_start, int y_end, int width)
        {
            Room room = Room(width, width); // создаем новую комнату с указанными размерами
            // -------- Задаем координаты -------- //
            int x = random(x_start, x_end+1), y = random(y_start, y_end+1);
            room.set_x(x);
            room.set_y(y);

            return room;
        }
        //--------------------------------------------------------------------------------------//

        int Room_Generate::Find_center_second(std::vector<split_leaf> leaves)
        {

            split_leaf leaf;
            int i = 0, count_of_leafs = leaves.size(), res = 0;

            while (i<count_of_leafs)
            {
                leaf = leaves[i];
                if ((leaf.j==0) && (leaf.i>leaves[res].i))
                    res = i;
                i++;
            }
            return res;
        }

        int Room_Generate::Find_center_third(std::vector<split_leaf> leaves)
        {

            split_leaf leaf;
            int i = 0, count_of_leafs = leaves.size(), res = 0;

            while (i<count_of_leafs)
            {
                leaf = leaves[i];
                if ((leaf.i==0) && (leaf.j>leaves[res].j))
                    res = i;
                i++;
            }
            return res;
        }

        // ------------------------------ Генерация всех комнат ------------------------------- //
        std::vector<Room> Room_Generate::Generate_Rooms(std::vector<std::vector<split_leaf>> leaves, int min_room, int mid_room, int max_room, int map_height, int map_width, int min_distance)
        {
            std::vector<Room> rooms = std::vector<Room>();


            int count_of_leafs= leaves[3].size(); // количество разбиений
            split_leaf cur_leaf;   // текущее разбиение
            int width; // размер комнаты
            int fin_room; // комната финала - портал

            // --------------------- Базы команд первая и последняя комната --------------------- //
            cur_leaf = leaves[0][0];
            width = mid_room;
            rooms.push_back(Room(width, width, cur_leaf.j, cur_leaf.i));

            cur_leaf = leaves[3][count_of_leafs-1];
            rooms.push_back(Room(width,width,
                                 map_width-width, map_height - width));
            //cur_leaf.j+ (map_width/2) +  cur_leaf.width - width, cur_leaf.i + (map_height/2) + cur_leaf.height - width));


            // ------------------------- Портал - центральная комната --------------------------- //
            rooms.push_back(Room(max_room,max_room, map_width/2-max_room/2, map_height/2-max_room/2));

            // -------------------------- Первая часть комнат ------------------------------- //
            count_of_leafs = leaves[0].size();
            for (int i = 1; i < count_of_leafs-1; i++)
            {
                cur_leaf = leaves[0][i];
                width = random(min_room, mid_room+1);
                rooms.push_back(GenerateRoom(cur_leaf.j+min_distance, cur_leaf.j+cur_leaf.width - width,
                cur_leaf.i+min_distance, cur_leaf.i+cur_leaf.height-width, width));
            }
            // ------------------------- Вторая часть комнат -------------------------------- //
            count_of_leafs = leaves[1].size();
            fin_room = Find_center_second(leaves[1]);
            for (int i = 0; i < count_of_leafs; i++)
            {
                if (i != fin_room)
                {
                    cur_leaf = leaves[1][i];
                    width = random(min_room, mid_room+1);
                    rooms.push_back(GenerateRoom(cur_leaf.j+(map_width/2)+min_distance, cur_leaf.j+ (map_width/2) +cur_leaf.width - width,
                    cur_leaf.i+min_distance, cur_leaf.i+cur_leaf.height-width, width));
                }
            }
            // ------------------------- Третья часть комнат -------------------------------- //
            count_of_leafs = leaves[2].size();
            fin_room = Find_center_third(leaves[2]);
            for (int i = 0; i < count_of_leafs; i++)
            {
                if (i != fin_room)
                {
                    cur_leaf = leaves[2][i];
                    width = random(min_room, mid_room+1);
                    rooms.push_back(GenerateRoom(cur_leaf.j+min_distance, cur_leaf.j +cur_leaf.width - width,
                    cur_leaf.i + (map_height/2)+min_distance, cur_leaf.i + (map_height/2) +cur_leaf.height-width, width));
                }

            }
            // -------------------------- Последняя часть комнат ------------------------------- //
            count_of_leafs = leaves[3].size();
            for (int i = 1; i < count_of_leafs-1; i++)
            {
                cur_leaf = leaves[3][i];
                width = random(min_room, mid_room+1);
                rooms.push_back(GenerateRoom(cur_leaf.j+(map_width/2)+min_distance, cur_leaf.j+ (map_width/2) +cur_leaf.width - width,
                cur_leaf.i + (map_height/2)+min_distance, cur_leaf.i + (map_height/2) +cur_leaf.height-width, width));
            }

            return rooms;

        }
        //--------------------------------------------------------------------------------------//
