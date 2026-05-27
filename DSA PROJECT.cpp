#include <iostream>
#include <cstdlib>   
using namespace std;

const int ROWS = 8;
const int COLS = 8;

char maze[ROWS][COLS] = {
    {'S', '.', '#', '.', '.', '.', '#', '.'},
    {'#', '.', '#', '.', '#', '.', '#', '.'},
    {'.', '.', '.', '.', '#', '.', '.', '.'},
    {'#', '#', '.', '#', '.', '#', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '#', '.'},
    {'.', '#', '#', '#', '#', '.', '#', '.'},
    {'.', '.', '.', '.', '.', '.', '.', '.'},
    {'#', '#', '#', '#', '#', '#', '.', 'E'}
};

int playerX = 0;
int playerY = 0;
bool visited[ROWS][COLS];
int dx[4] = {-1, 1, 0, 0}; 
int dy[4] = {0, 0, -1, 1};

void displayMaze() {
    cout << "Maze:\n\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == playerX && j == playerY)
                cout << "P ";
            else
                cout << maze[i][j] << " ";
        }
        cout << endl;
    }
}

bool isValidMove(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS)
        return false;
    if (maze[x][y] == '#')
        return false;
    return true;
}

bool dfsReachable(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS)
        return false;
    if (maze[x][y] == '#' || visited[x][y])
        return false;
    if (maze[x][y] == 'E')
        return true;

    visited[x][y] = true;

    if (dfsReachable(x - 1, y)) return true;
    if (dfsReachable(x + 1, y)) return true;
    if (dfsReachable(x, y - 1)) return true;
    if (dfsReachable(x, y + 1)) return true;

    return false;
}

void movePlayer(char move) {
    int newX = playerX;
    int newY = playerY;

    if (move == 'W' || move == 'w') newX--;
    else if (move == 'S' || move == 's') newX++;
    else if (move == 'A' || move == 'a') newY--;
    else if (move == 'D' || move == 'd') newY++;
    else {
        cout << "Invalid input!\n";
        return;
    }

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            visited[i][j] = false;

    if (dfsReachable(newX, newY)) {
        playerX = newX;
        playerY = newY;
    } else {
        cout << "Move blocked! No path to exit.\n";
    }
}

// BFS without queue library
struct Point {
    int x, y;
};

int bfsShortestPath(int startX, int startY) {
    bool visitedBFS[ROWS][COLS] = {false};
    int distance[ROWS][COLS] = {0};

    Point queue[ROWS * COLS];
    int front = 0, back = 0;

    queue[back++] = {startX, startY};
    visitedBFS[startX][startY] = true;

    while (front < back) {
        Point p = queue[front++];
        int x = p.x, y = p.y;

        if (maze[x][y] == 'E')
            return distance[x][y];

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < ROWS &&
                ny >= 0 && ny < COLS &&
                maze[nx][ny] != '#' &&
                !visitedBFS[nx][ny]) {

                visitedBFS[nx][ny] = true;
                distance[nx][ny] = distance[x][y] + 1;
                queue[back++] = {nx, ny};
            }
        }
    }
    return -1;
}

void resetGame() {
    playerX = 0;
    playerY = 0;

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            visited[i][j] = false;
}

int main() {
    char choice;

    while (true) {
        system("cls");      

        displayMaze();

        if (maze[playerX][playerY] == 'E') {
            cout << "\nCongratulations! You escaped the maze.\n";
            break;
        }

        cout << "\nControls:\n";
        cout << "W - Up\n";
        cout << "S - Downward\n";
        cout << "A - Back\n";
        cout << "D - Forward\n";
        cout << "B - Shortest path (BFS)\n";
        cout << "R - Reset Game\n";
        cout << "Q - Quit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 'Q' || choice == 'q')
            break;

        if (choice == 'R' || choice == 'r') {
            resetGame();
            continue;
        }

        if (choice == 'B' || choice == 'b') {
            int steps = bfsShortestPath(playerX, playerY);
            if (steps == -1)
                cout << "\nNo path to exit.\n";
            else
                cout << "\nShortest path to exit: " << steps << " steps.\n";

            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
            continue;
        }

        movePlayer(choice);
    }

    return 0;
}

