#include "global.h"
#include  <stdio.h>
#include  <Stack.h>

void initializeMaze();

namespace{
    const int MAX_STACK_SIZE = 100; //for max elems 7*14      
} 

class Maze{
    public:
        bool IsWallX(int nx, int ny, int dir){   //dir == 1  right wall    dir == -1   left wall
            if (dir == 1 ) return maze_wallsX[ nx +1 ][ny];
            if (dir == -1) return maze_wallsX[ nx ][ny];
            //error if (dir !=+-1)
            if (dir == 0 ) printf("Maze error   IsWallX incorrect usage! \n");   
        }
        bool IsWallY(int nx, int ny, int dir){   //dir == 1  dwon wall    dir == -1   up wall
            if (dir == 1 ) return maze_wallsY[ nx ][ny + 1];
            if (dir == -1) return maze_wallsY[ nx ][ny];
            //error if (dir !=+-1)
            if (dir == 0 ) printf("Maze error   IsWallY incorrect usage! \n");   
        }
    private:
        void generateMaze(int startX, int startY);
        bool isValidCell(int X, int Y);
        bool maze_wallsX[COLCOUNT+1][ROWCOUNT] {true};
        bool maze_wallsY[COLCOUNT][ROWCOUNT+1] {true};
};

struct Cell{
         int x = -1;
         int y = -1;
};
  
bool Maze::isValidCell(int x, int y) {
    if ((x<0) || (x>COLCOUNT) ) return false;
    if ((y<0) || (y>ROWCOUNT) ) return false;
    return true;
}

void Maze::generateMaze(int startX, int startY )
{
    bool visited[ROWCOUNT][COLCOUNT]{false}; // i j   - - columns  
    Stack<Cell> localstack;
    const int direction_x[4] = {0, 1, 0, -1}; // up  right down left
    const int direction_y[4] = {-1, 0, 1, 0};
    Cell loccell ;loccell.x = startX;  loccell.y = startY;
    localstack.push(loccell);
    visited[startY][startX] = true;
    while ( localstack.length()!=0 ){
        Cell current = localstack.pop();
        int availableDirs[4];
        int count = 0;
        for (int dir = 0; dir < 4; dir++) {
            int nx = current.x + direction_x[dir];
            int ny = current.y + direction_y[dir];
            if (isValidCell(nx, ny) && !visited[ny][nx]) {
                availableDirs[count++] = dir;
            }
        }

        if (count > 0) {
            // Возвращаем текущую клетку в стек
            localstack.push(current);    
            // Выбираем случайное направление
            int dir = availableDirs[rand() % count];
            int nx = current.x + direction_x[dir];
            int ny = current.y + direction_y[dir];
                
            // Убираем стену между клетками
            int wallX = current.x * 2 + 1 + direction_x[dir];
            int wallY = current.y * 2 + 1 + direction_y[dir];

            if (direction_y[dir] ==0){ // x-oriented faces
                int Xface_number = -1;
                if (direction_x[dir] == -1) Xface_number = current.x;
                if (direction_x[dir] == 1) Xface_number = current.x + 1;
                maze_wallsX[Xface_number][ny] = false;
            }

            if (direction_x[dir] == 0){ //y-oriented fases
                int Yface_number =-1;
                if (direction_y[dir] == -1) Yface_number = current.y;
                if (direction_x[dir] == 1) Yface_number = current.y + 1;
                maze_wallsY[current.x][Yface_number] = false;
            }

            // Переходим к новой клетке
            visited[ny][nx] = 1;
            Cell newcell; newcell.x = nx; newcell.y = ny;
            localstack.push(newcell);
          }
    }







}