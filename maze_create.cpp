#include "global.h"
#include  <Stack.h>

void initializeMaze();

namespace{
    const int MAX_STACK_SIZE = 100; //for max elems 7*14      
} 

class Maze{
    public:

    private:

};

struct Cell{
         int x = -1;
         int y = -1;
};
  
// struct Stack{
//     struct Cell{
//         int x = -1;
//         int y = -1;
//     };  
//     Cell position[MAX_STACK_SIZE]{-1, -1};
//     int top = -1;
//     bool isStackEmpty(){
//         return (-1 == top);
//     }
//     //push()
// };


void generateMaze(int startX, int startY )
{
    bool visited[ROWCOUNT][COLCOUNT]{false}; // i j   - - columns
    char maze_walls[COLCOUNT*2][ROWCOUNT*2];
    StackT<Cell> localstack;
    const int direction_x[4] = {0, 1, 0, -1}; // up  right down left
    const int direction_y[4] = {-1, 0, 1, 0};
    localstack.push(startY, startX);
    visited[startY][startX] = true;
    


}