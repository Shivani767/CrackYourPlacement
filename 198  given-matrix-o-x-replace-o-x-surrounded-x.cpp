#include <iostream>

using namespace std;

void floodFillUtil(char mat[][6], int x, int y, char prevV, char newV) {
    if (x < 0 || x >= 6 || y < 0 || y >= 6)
        return;
    if (mat[x][y] != prevV)
        return;

    mat[x][y] = newV;

    floodFillUtil(mat, x+1, y, prevV, newV);
    floodFillUtil(mat, x-1, y, prevV, newV);
    floodFillUtil(mat, x, y+1, prevV, newV);
    floodFillUtil(mat, x, y-1, prevV, newV);
}

void replaceSurrounded(char mat[][6]) {
    // Step 1: Replace all 'O' with '-'
    for (int i=0; i<6; i++)
        for (int j=0; j<6; j++)
            if (mat[i][j] == 'O')
                mat[i][j] = '-';

    // Call floodFill for all '-' lying on edges
    for (int i=0; i<6; i++)   // Left side
        if (mat[i][0] == '-')
            floodFillUtil(mat, i, 0, '-', 'O');
    for (int i=0; i<6; i++)  //  Right side
        if (mat[i][5] == '-')
            floodFillUtil(mat, i, 5, '-', 'O');
    for (int i=0; i<6; i++)   // Top side
        if (mat[0][i] == '-')
            floodFillUtil(mat, 0, i, '-', 'O');
    for (int i=0; i<6; i++)  // Bottom side
        if (mat[5][i] == '-')
            floodFillUtil(mat, 5, i, '-', 'O');

    // Step 3: Replace all '-' with 'X'
    for (int i=0; i<6; i++)
        for (int j=0; j<6; j++)
            if (mat[i][j] == '-')
                mat[i][j] = 'X';
}

int main() {
    char mat[][6] =  {{'X', 'O', 'X', 'O', 'X', 'X'},
                     {'X', 'O', 'X', 'X', 'O', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'X'},
                     {'O', 'X', 'X', 'X', 'X', 'X'},
                     {'X', 'X', 'X', 'O', 'X', 'O'},
                     {'O', 'O', 'X', 'O', 'O', 'O'},
                    };
    replaceSurrounded(mat);

    for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++)
            cout << mat[i][j] << " ";
        cout << endl;
    }
    return 0;
}
