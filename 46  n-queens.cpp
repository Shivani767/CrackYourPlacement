class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> result;
        std::vector<std::string> board(n, std::string(n, '.'));
        backtrack(result, board, 0);
        return result;
    }

private:
    void backtrack(std::vector<std::vector<std::string>>& result, std::vector<std::string>& board, int row) {
        if (row == board.size()) {
            result.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); ++col) {
            if (isValid(board, row, col)) {
                board[row][col] = 'Q';
                backtrack(result, board, row + 1);
                board[row][col] = '.';
            }
        }
    }

    bool isValid(std::vector<std::string>& board, int row, int col) {
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false;
            if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q') return false;
            if (col + (row - i) < board.size() && board[i][col + (row - i)] == 'Q') return false;
        }
        return true;
    }
};
