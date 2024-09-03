class Solution {
  public:
    int findPair(int n, int x, vector<int> &arr) {
     std::sort(arr.begin(), arr.end());
    int start = 0;
    int end = 1;

    while (start < n && end < n) {
        int diff = arr[end] - arr[start];

        if (diff == x) {
            return 1;
        } else if (diff < x) {
            end++;
        } else {
            start++;
        }

        // Ensure that start and end are not the same
        if (start == end) {
            end++;
        }
    }

    return -1;
    }
};
