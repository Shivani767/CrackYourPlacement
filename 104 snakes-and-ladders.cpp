class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<bool> visited(n * n + 1, false);
        queue<int> q;
        q.push(1);
        visited[1] = true;
        int moves = 0;
        
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int curr = q.front();
                q.pop();
                if (curr == n * n) {
                    return moves;
                }
                for (int j = 1; j <= 6; j++) {
                    int next = curr + j;
                    if (next > n * n) {
                        break;
                    }
                    int r = (next - 1) / n, c = (next - 1) % n;
                    if (r % 2 == 1) {
                        c = n - 1 - c;
                    }
                    r = n - 1 - r;
                    if (board[r][c] != -1) {
                        next = board[r][c];
                    }
                    if (!visited[next]) {
                        q.push(next);
                        visited[next] = true;
                    }
                }
            }
            moves++;
        }
        
        return -1;
    }
};
