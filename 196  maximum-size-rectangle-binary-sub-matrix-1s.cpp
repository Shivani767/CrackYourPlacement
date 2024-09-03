#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int maxHist(vector<int>& row) {
    stack<int> result;
    int max_area = 0;
    int area = 0;

    for (int i = 0; i < row.size(); i++) {
        if (result.empty() || row[result.top()] <= row[i])
            result.push(i++);
        else {
            int top_val = row[result.top()];
            result.pop();
            area = top_val * i;

            if (!result.empty())
                area = top_val * (i - result.top() - 1);
            max_area = max(area, max_area);
        }
    }

    while (!result.empty()) {
        int top_val = row[result.top()];
        result.pop();
        area = top_val * row.size();
        if (!result.empty())
            area = top_val * (row.size() - result.top() - 1);

        max_area = max(area, max_area);
    }
    return max_area;
}

int maxRectangle(vector<vector<int>>& A) {
    int result = maxHist(A[0]);

    for (int i = 1; i < A.size(); i++) {
        for (int j = 0; j < A[i].size(); j++) {
            if (A[i][j])
                A[i][j] += A[i - 1][j];
        }

        result = max(result, maxHist(A[i]));
    }

    return result;
}

int main() {
    vector<vector<int>> A = {
        {0, 1, 1, 0},
        {1, 1, 1, 1},
        {1, 1, 1, 1},
        {1, 1, 0, 0},
    };

    cout << "Area of maximum rectangle is " << maxRectangle(A) << endl;

    return 0;
}
