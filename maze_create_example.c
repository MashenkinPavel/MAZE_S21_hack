#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COLS 15
#define ROWS 10
#define DISPLAY_COLS (COLS * 2 + 1)
#define DISPLAY_ROWS (ROWS * 2 + 1)
#define MAX_STACK_SIZE 1000

typedef struct {
    int x;
    int y;
} Cell;

typedef struct {
    Cell items[MAX_STACK_SIZE];
    int top;
} Stack;

char maze[DISPLAY_ROWS][DISPLAY_COLS];
int visited[ROWS][COLS];
Stack stack;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {-1, 0, 1, 0};

// Функции работы со стеком
void initStack(Stack *s) {
    s->top = -1;
}

int isStackEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, Cell cell) {
    if (s->top < MAX_STACK_SIZE - 1) {
        s->items[++(s->top)] = cell;
    }
}

Cell pop(Stack *s) {
    return s->items[(s->top)--];
}

// Инициализация лабиринта
void initializeMaze() {
    for (int y = 0; y < DISPLAY_ROWS; y++) {
        for (int x = 0; x < DISPLAY_COLS; x++) {
            maze[y][x] = '#';
        }
    }
    
    for (int y = 0; y < ROWS; y++) {
        for (int x = 0; x < COLS; x++) {
            visited[y][x] = 0;
            int displayX = x * 2 + 1;
            int displayY = y * 2 + 1;
            maze[displayY][displayX] = ' ';
        }
    }
}

// Проверка валидности координат клетки
int isValidCell(int x, int y) {
    return (x >= 0 && x < COLS && y >= 0 && y < ROWS);
}

// Генерация лабиринта с использованием стека
void generateMazeWithStack(int startX, int startY) {
    initStack(&stack);
    push(&stack, (Cell){startX, startY});
    visited[startY][startX] = 1;
    
    while (!isStackEmpty(&stack)) {
        Cell current = pop(&stack);
        
        // Проверяем доступные направления
        int availableDirs[4];
        int count = 0;
        
        for (int dir = 0; dir < 4; dir++) {
            int nx = current.x + dx[dir];
            int ny = current.y + dy[dir];
            
            if (isValidCell(nx, ny) && !visited[ny][nx]) {
                availableDirs[count++] = dir;
            }
        }
        
        if (count > 0) {
            // Возвращаем текущую клетку в стек
            push(&stack, current);
            
            // Выбираем случайное направление
            int dir = availableDirs[rand() % count];
            int nx = current.x + dx[dir];
            int ny = current.y + dy[dir];
            
            // Убираем стену между клетками
            int wallX = current.x * 2 + 1 + dx[dir];
            int wallY = current.y * 2 + 1 + dy[dir];
            maze[wallY][wallX] = ' ';
            
            // Переходим к новой клетке
            visited[ny][nx] = 1;
            push(&stack, (Cell){nx, ny});
        }
    }
}

// Отображение лабиринта
void printMaze() {
    printf("Лабиринт %dx%d (с тонкими стенками, стековая версия):\n", COLS, ROWS);
    printf("# - стена\n");
    printf("  - проход\n\n");
    
    for (int y = 0; y < DISPLAY_ROWS; y++) {
        for (int x = 0; x < DISPLAY_COLS; x++) {
            printf("%c", maze[y][x]);
        }
        printf("\n");
    }
}

// Создание входа и выхода
void createEntranceExit() {
    maze[0][1] = ' ';
    maze[DISPLAY_ROWS-1][DISPLAY_COLS-2] = ' ';
}

int main() {
    srand(time(NULL));
    
    printf("Генерация лабиринта (стековая версия)...\n");
    
    initializeMaze();
    generateMazeWithStack(0, 0);
    createEntranceExit();
    printMaze();
    
    return 0;
}