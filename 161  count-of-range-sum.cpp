#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    tree<long long, null_type, less_equal<long long>, rb_tree_tag, tree_order_statistics_node_update> T;
    
    // lower <= sum[j] - sum[i] <= upper
    // sum[j] - sum[i] >= lower
    // sum[j] - sum[i] <= upper
    // where i < j
    
    // given sum[j], find the number of i such that 
    // 1. i < j 
    // 2. sum[j] - upper <= sum[i] <= sum[j] - lower
    
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        long long sum = 0, ans = 0;
        // normalise as lower <= sum[j] - 0 <= upper
        T.insert(0);
        for (auto x : nums) {
            // prefix sum
            sum += x;
            // count the range
            ans += T.order_of_key(sum - lower + 1) - T.order_of_key(sum - upper);
            // update T
            T.insert(sum);
        }
        return ans;
    }
};
