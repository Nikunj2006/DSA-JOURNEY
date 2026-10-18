class Solution {
public:
    static const long long MOD = 1000000007;

    long long comb[1001][1001];

    long long solve(vector<int>& nums) {
        if (nums.size() <= 2) return 1;

        int root = nums[0];
        vector<int> left, right;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < root)
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }

        long long L = solve(left);
        long long R = solve(right);

        int l = left.size();
        int r = right.size();

        return comb[l + r][l] * L % MOD * R % MOD;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i <= n; i++) {
            comb[i][0] = comb[i][i] = 1;
            for (int j = 1; j < i; j++)
                comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % MOD;
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }
};