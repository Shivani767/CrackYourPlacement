class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) return {};
        int m = matrix.size(), n = matrix[0].size();
        vector<int> res(m * n);
        int idx = 0, left = 0, right = n - 1, top = 0, bottom = m - 1;
        while (left <= right && top <= bottom) {
            for (int i = left; i <= right; i++) res[idx++] = matrix[top][i];
            top++;
            for (int i = top; i <= bottom; i++) res[idx++] = matrix[i][right];
            right--;
            if (top <= bottom) {
                for (int i = right; i >= left; i--) res[idx++] = matrix[bottom][i];
                bottom--;
            }
            if (left <= right) {
                for (int i = bottom; i >= top; i--) res[idx++] = matrix[i][left];
                left++;
            }
        }
        return res;
    }
};
