class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int total = 0;
        for (int i = 0; i < n; i++) {
            total += cardPoints[i];
        }
        
        int windowSize = n - k;
        int minWindowSum = INT_MAX;
        int windowSum = 0;
        
        for (int i = 0; i < n; i++) {
            windowSum += cardPoints[i];
            if (i >= windowSize) {
                windowSum -= cardPoints[i - windowSize];
            }
            if (i >= windowSize - 1) {
                minWindowSum = min(minWindowSum, windowSum);
            }
        }
        
        return total - minWindowSum;
    }
};
