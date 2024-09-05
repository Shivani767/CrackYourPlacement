class Solution {
public:
    // Function to find maximum of minimums of every window size.
    vector<int> maxOfMin(int arr[], int n) {
        vector<int> left(n), right(n), result(n + 1, 0);
        
        // Initialize left and right boundary arrays
        stack<int> s;
        
        // Calculate nearest smaller to left
        for (int i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            left[i] = (s.empty()) ? -1 : s.top();
            s.push(i);
        }
        
        // Clear the stack for next use
        while (!s.empty()) s.pop();
        
        // Calculate nearest smaller to right
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && arr[s.top()] >= arr[i])
                s.pop();
            right[i] = (s.empty()) ? n : s.top();
            s.push(i);
        }
        
        // Calculate maximum of minimums for each window size
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1; // window size where arr[i] is the minimum
            result[len] = max(result[len], arr[i]);
        }
        
        // Fill the remaining entries of result array
        for (int i = n - 1; i >= 1; i--) {
            result[i] = max(result[i], result[i + 1]);
        }
        
        // Remove the first element (index 0) as it is not needed
        result.erase(result.begin());
        
        return result;
    }
};
