
class PrimMaze;

void create_maze(int cols, int rows){
    PrimMaze generator(cols, rows);
    generator.generate();
}


#include <vector>
#include <queue>

class MAZE_vector(int elementSize, int size){
       
    private:

}


class PrimMaze {
private:
    int width, height;
    bool walls[COLCOUNT][RWOCOUNT] {1};
    //std::vector<std::vector<bool>> walls;

    struct Frontier {
        int x, y, fromX, fromY;
        Frontier(int x, int y, int fx, int fy) : x(x), y(y), fromX(fx), fromY(fy) {}
    };

public:
    PrimMaze(int w, int h) : width(w), height(h) {
        //walls.resize(height, std::vector<bool>(width, true));
    }

    void generate(int startX = 1, int startY = 1) {
        std::vector<Frontier> frontiers;
        
        walls[startY][startX] = false;
        addFrontiers(startX, startY, frontiers);

        while (!frontiers.empty()) {
            int idx = rand() % frontiers.size();
            Frontier f = frontiers[idx];
            frontiers.erase(frontiers.begin() + idx);

            if (walls[f.y][f.x]) {
                walls[f.y][f.x] = false;
                walls[(f.y + f.fromY) / 2][(f.x + f.fromX) / 2] = false;
                addFrontiers(f.x, f.y, frontiers);
            }
        }
    }

private:
    void addFrontiers(int x, int y, std::vector<Frontier>& frontiers) {
        int directions[4][2] = {{0, -2}, {0, 2}, {-2, 0}, {2, 0}};
        
        for (auto [dx, dy] : directions) {
            int nx = x + dx, ny = y + dy;
            if (nx > 0 && nx < width-1 && ny > 0 && ny < height-1 && 
                walls[ny][nx]) {
                frontiers.push_back(Frontier(nx, ny, x, y));
            }
        }
    }
};


void draw_maze(){


}