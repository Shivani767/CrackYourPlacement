class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        auto cmp = [&matrix](pair<int, int> a, pair<int, int> b) {
            return matrix[a.first][a.second] > matrix[b.first][b.second];
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        pq.push({0, 0});
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        visited[0][0] = true;
        int cnt = 0, res = 0;
        while (!pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            cnt++;
            res = matrix[x][y];
            if (cnt == k) break;
            if (x + 1 < n && !visited[x + 1][y]) {
                pq.push({x + 1, y});
                visited[x + 1][y] = true;
            }
            if (y + 1 < n && !visited[x][y + 1]) {
                pq.push({x, y + 1});
                visited[x][y + 1] = true;
            }
        }
        return res;
    }
};
