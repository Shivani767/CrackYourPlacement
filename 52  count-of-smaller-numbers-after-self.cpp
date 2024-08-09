class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);
        sort(idx.begin(), idx.end(), [&nums](int a, int b) {
            return nums[a] > nums[b];
        });
        vector<int> bit(n + 1);
        for (int i = 0; i < n; i++) {
            res[idx[i]] = query(bit, idx[i]);
            update(bit, idx[i] + 1, 1);
        }
        return res;
    }

private:
    void update(vector<int>& bit, int i, int val) {
        while (i < bit.size()) {
            bit[i] += val;
            i += i & -i;
        }
    }

    int query(vector<int>& bit, int i) {
        int res = 0;
        while (i > 0) {
            res += bit[i];
            i -= i & -i;
        }
        return res;
    }
};
