#include "Maze_Generate.h"

// -------------------- SET THE ROOM ON THE MAP -------------------- //
        void Maze_Generate::Set_Room( std::vector<std::vector<Cell>>& maze_map, Room room)
        {
            int end_i = room.Y() + room.Height(), // set the last indexes of X and Y coordinates
                end_j = room.X() + room.Width();

            for (int i = room.Y(); i < end_i; ++i) // go by height
            {
                for (int j = room.X(); j < end_j; ++j) // go by weight
                {
                    if (j != end_j-1) // if it`s not a last X coordinate
                    {
                        maze_map[i][j].Remove_RightWall(); // remove vertical wall
                    }
                    if ( i != end_i -1) // if it`s not a last Y coordinate
                    {
                        maze_map[i][j].Remove_BottomWall(); // remove horizontal wall
                    }
                }
            }
        }
        //-------------------------------------------------------------------//


        std::vector<Room> Maze_Generate::Get_rooms(int height, int width, int min_room, int mid_room, int max_room, int distance)
        {

            // -------- Получаем разбиение карты  --------- //
            std::vector<std::vector<split_leaf>> leaves = std::vector<std::vector<split_leaf>>();
            leaves.push_back(Map_Splitter().Split(height / 2, width / 2, mid_room + distance, mid_room + distance));
            leaves.push_back(Map_Splitter().Split(height / 2, width / 2, mid_room + distance, mid_room + distance));
            leaves.push_back(Map_Splitter().Reverse_Split(leaves[1], height / 2, width / 2));
            leaves.push_back(Map_Splitter().Reverse_Split(leaves[0], height / 2, width / 2));

            // ------------ Генерируем комнаты ------------ //
            std::vector<Room> rooms = Room_Generate().Generate_Rooms(leaves, min_room, mid_room, max_room, height, width, distance);

            return rooms;
        }
        ///
        /// height = width = 72
        /// rooms_count = 16
        /// min_room = 4, mid_room = 8, max_room = 9
        ///
        std::vector<std::vector<Cell>>  Maze_Generate::Get_map(int height, int width, std::vector<Room> rooms)
        {
            std::vector<std::vector<Cell>>  maze_map; // The map
            Ellers_Algorithm maze = Ellers_Algorithm(); // Maze Generation Class to generate the maze

            maze.Generate(height, width); // Generate the maze
            maze_map = maze.Maze(); // set the map the maze generation result

            // Set each room on the map
            for (long unsigned int k = 0; k < rooms.size(); ++k)
            {
                Set_Room(maze_map, rooms[k]);
            }
            return maze_map;
        }
