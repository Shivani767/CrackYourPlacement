class Solution {
public:
    int countArrangement(int n) {
        std::vector<bool> visited(n + 1, false);
        return backtrack(n, 1, visited);
    }

private:
    int backtrack(int n, int pos, std::vector<bool>& visited) {
        if (pos > n) return 1;
        int count = 0;
        for (int i = 1; i <= n; ++i) {
            if (!visited[i] && (i % pos == 0 || pos % i == 0)) {
                visited[i] = true;
                count += backtrack(n, pos + 1, visited);
                visited[i] = false;
            }
        }
        return count;
    }
};
