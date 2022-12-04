#include <iostream>
#include<cstdlib>
#include <ctime>
#include <vector>
#include "Cell.h"
#include "Room.h"
#include "Maze_Generate.h"

using namespace std;

int main()
{
    srand(time(0));
    int height = 35;
    int width = 35;

    std::vector<Room> rooms = Maze_Generate().Get_rooms(height, width, 3, 4, 5, 2);
    std::vector<std::vector<Cell>> cells = Maze_Generate().Get_map(height, width, rooms);
    for (int i = 0; i < cells.size(); ++i)
    {
        for (int j = 0; j < cells[i].size(); ++j)
        {
            cells[i][j].Display_RightWall();
        }
        cout<<endl;
        for (int j = 0; j < cells[i].size(); ++j)
        {
            cells[i][j].Display_BottomWall();
        }
        cout<<endl;
    }
    /*Ellers_Algorithm generateAlgorithm = Ellers_Algorithm(10, 10);
    generateAlgorithm.Generate(10,10);
    vector<vector<Cell>> mazeMap = generateAlgorithm.Maze();
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            mazeMap[i][j].Display_RightWall();
        }
        cout<<endl;
        for (int j = 0; j < 10; ++j)
        {
            mazeMap[i][j].Display_BottomWall();
        }
        cout<<endl;
    }*/
    cout << "Hello world!" << endl;
    return 0;
}
