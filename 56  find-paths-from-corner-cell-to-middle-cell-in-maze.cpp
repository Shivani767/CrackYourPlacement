#include <bits/stdc++.h>
using namespace std;

// Define the maze size
#define N 9

// Function to check if a cell is valid (within bounds and not visited)
bool isValid(set<pair<int, int>> &visited, pair<int, int> pt) {
    return (pt.first >= 0) && (pt.first < N) &&
           (pt.second >= 0) && (pt.second < N) &&
           (visited.find(pt) == visited.end());
}

// Function to print the path from source to middle coordinate
void printPath(list<pair<int, int>> &path) {
    for (auto it = path.begin(); it != path.end(); it++) {
        cout << "(" << it->first << ", " << it->second << ") -> ";
    }
    cout << "MID" << endl << endl;
}

// Define the directions for movement (up, down, left, right)
int row[] = {-1, 1, 0, 0};
int col[] = {0, 0, -1, 1};

// Define the coordinates of the four corners of the maze
int _row[] = {0, 0, N - 1, N - 1};
int _col[] = {0, N - 1, 0, N - 1};

// Recursive function to find a path from the current cell to the middle cell
void findPathInMazeUtil(int maze[N][N], list<pair<int, int>> &path,
                        set<pair<int, int>> &visited, pair<int, int> &curr) {
    // If we have reached the destination cell, print the path
    if (curr.first == N / 2 && curr.second == N / 2) {
        printPath(path);
        return;
    }

    // Explore all four directions from the current cell
    for (int i = 0; i < 4; ++i) {
        int n = maze[curr.first][curr.second];
        int x = curr.first + row[i] * n;
        int y = curr.second + col[i] * n;
        pair<int, int> next = make_pair(x, y);

        // If the next cell is valid, mark it as visited and add it to the path
        if (isValid(visited, next)) {
            visited.insert(next);
            path.push_back(next);

            // Recurse to explore the next cell
            findPathInMazeUtil(maze, path, visited, next);

            // Backtrack: remove the cell from the path and visited set
            path.pop_back();
            visited.erase(next);
        }
    }
}

// Function to find a path from any of the four corner cells to the middle cell
void findPathInMaze(int maze[N][N]) {
    list<pair<int, int>> path;
    set<pair<int, int>> visited;

    // Consider each corner as the starting point and search in the maze
    for (int i = 0; i < 4; ++i) {
        int x = _row[i];
        int y = _col[i];
        pair<int, int> pt = make_pair(x, y);

        // Mark the starting cell as visited and add it to the path
        visited.insert(pt);
        path.push_back(pt);

        findPathInMazeUtil(maze, path, visited, pt);

        // Backtrack: remove the starting cell from the path and visited set
        path.pop_back();
        visited.erase(pt);
    }
}

int main() {
    int maze[N][N] = {
        {3, 5, 4, 4, 7, 3, 4, 6, 3},
        {6, 7, 5, 6, 6, 2, 6, 6, 2},
        {3, 3, 4, 3, 2, 5, 4, 7, 2},
        {6, 5, 5, 1, 2, 3, 6, 5, 6},
        {3, 3, 4, 3, 0, 1, 4, 3, 4},
        {3, 5, 4, 3, 2, 2, 3, 3, 5},
        {3, 5, 4, 3, 2, 6, 4, 4, 3},
        {3, 5, 1, 3, 7, 5, 3, 6, 4},
        {6, 2, 4, 3, 4, 5, 4, 5, 1}
    };

    findPathInM
