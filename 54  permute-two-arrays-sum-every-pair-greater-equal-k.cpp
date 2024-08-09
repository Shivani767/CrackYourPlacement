#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> P(n, 1);

    // Calculate product of all elements to the left of each index
    int left_product = 1;
    for (int i = 0; i < n; i++) {
        P[i] *= left_product;
        left_product *= nums[i];
    }

    // Calculate product of all elements to the right of each index
    int right_product = 1;
    for (int i = n - 1; i >= 0; i--) {
        P[i] *= right_product;
        right_product *= nums[i];
    }

    return P;
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> P = productExceptSelf(nums);

    for (int i = 0; i < n; i++) {
        cout << P[i] << " ";
    }
    cout << endl;

    return 0;
}
