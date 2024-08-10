class BIT {
    constructor(n) {
        this.n = n;
        this.tree = new Array(n + 1).fill(0);
    }

    update(i, val) {
        while (i <= this.n) {
            this.tree[i] += val;
            i += i & -i;
        }
    }

    query(i) {
        let sum = 0;
        while (i > 0) {
            sum += this.tree[i];
            i -= i & -i;
        }
        return sum;
    }
}

var countSmaller = function(nums) {
    let sortedNums = [...new Set(nums)].sort((a, b) => a - b);
    let map = {};
    for (let i = 0; i < sortedNums.length; i++) {
        map[sortedNums[i]] = i + 1;
    }

    let res = new Array(nums.length).fill(0);
    let bit = new BIT(nums.length);
    for (let i = nums.length - 1; i >= 0; i--) {
        res[i] = bit.query(map[nums[i]] - 1);
        bit.update(map[nums[i]], 1);
    }

    return res;
};
