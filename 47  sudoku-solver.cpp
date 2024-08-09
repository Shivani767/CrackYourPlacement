class Solution {
public:
    bool isValid(std::vector<std::vector<char>>& board, int row, int col, char num) {
        // Check the row
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == num) return false;
        }
        // Check the column
        for (int i = 0; i < 9; ++i) {
            if (board[i][col] == num) return false;
        }
        // Check the 3x3 sub-box
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[startRow + i][startCol + j] == num) return false;
            }
        }
        return true;
    }

    bool solve(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; ++num) {
                        if (isValid(board, i, j, num)) {
                            board[i][j] = num;
                            if (solve(board)) return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        solve(board);
    }
};
