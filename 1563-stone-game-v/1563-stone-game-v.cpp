class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        const int n = stoneValue.size();
        vector<vector<int>> mem(n, vector<int>(n, INT_MIN));
        vector<int> prefix(n + 1);
        partial_sum(stoneValue.begin(), stoneValue.end(), prefix.begin() + 1);
        return stoneGameV(stoneValue, 0, n - 1, prefix, mem);
    }
private:
    int stoneGameV(const vector<int>& stoneValue, int i, int j,
                   const vector<int>& prefix, vector<vector<int>>& mem) {
        if (i == j) return 0;
        if (mem[i][j] > 0) return mem[i][j];
        for (int p = i; p < j; ++p) {
            const int leftSum = prefix[p + 1] - prefix[i];
            const int rightSum = prefix[j + 1] - prefix[p + 1];
            if (leftSum < rightSum) {
                mem[i][j] = max(mem[i][j], leftSum + stoneGameV(stoneValue, i, p, prefix, mem));
            } else if (leftSum > rightSum) {
                mem[i][j] = max(mem[i][j], rightSum + stoneGameV(stoneValue, p + 1, j, prefix, mem));
            } else {
                mem[i][j] = max({mem[i][j],
                                leftSum + stoneGameV(stoneValue, i, p, prefix, mem),
                                rightSum + stoneGameV(stoneValue, p + 1, j, prefix, mem)});
            }
        }
        return mem[i][j];
    }
};   