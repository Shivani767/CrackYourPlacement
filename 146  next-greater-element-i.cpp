class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> s;
        for (int num : nums2) {
            while (!s.empty() && s.top() < num) {
                map[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        vector<int> ans;
        for (int num : nums1) {
            if (map.find(num) != map.end()) {
                ans.push_back(map[num]);
            } else {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};
