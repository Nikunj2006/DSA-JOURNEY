class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }

private:
    pair<int, int> dfs(TreeNode* node, int& ans) {
        if (!node) return {0, 0};
        auto [lSum, lCnt] = dfs(node->left, ans);
        auto [rSum, rCnt] = dfs(node->right, ans);
        int sum = lSum + rSum + node->val;
        int cnt = lCnt + rCnt + 1;
        if (sum / cnt == node->val) ++ans;
        return {sum, cnt};
    }
};   