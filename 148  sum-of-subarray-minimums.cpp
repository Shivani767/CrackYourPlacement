class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MOD = 1e9 + 7;
        int n = arr.size();
        int res = 0;
        stack<int> st;
        
        for (int i = 0; i <= n; i++) {
            int cur = (i == n) ? 0 : arr[i];
            while (!st.empty() && arr[st.top()] > cur) {
                int idx = st.top();
                st.pop();
                int left = st.empty() ? -1 : st.top();
                res = (res + (long long)arr[idx] * (idx - left) * (i - idx)) % MOD;
            }
            st.push(i);
        }
        
        return res;
    }
};
