var pathSum = function(root, targetSum) {
    let count = { 0: 1 };
    return dfs(root, targetSum, 0, count);
};

function dfs(node, targetSum, currSum, count) {
    if (!node) return 0;
    currSum += node.val;
    let res = count[currSum - targetSum] || 0;
    count[currSum] = (count[currSum] || 0) + 1;
    res += dfs(node.left, targetSum, currSum, count);
    res += dfs(node.right, targetSum, currSum, count);
    count[currSum]--;
    return res;
}
