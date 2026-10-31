class Solution {
public:
    static const int MOD = 1000000007;

    int m, n;
    vector<vector<int>> grid;
    vector<vector<array<int,2>>> memo;

    int jump(int r, int c, int dir) {
        if (r < 0 || r >= m || c < 0 || c >= n)
            return -1;

        if (grid[r][c] == 0)
            return r * n + c;

        int &res = memo[r][c][dir];
        if (res != -2)
            return res;

        if (dir == 0)
            res = jump(r + 1, c, 1);
        else
            res = jump(r, c + 1, 0);

        return res;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        this->grid = grid;
        m = grid.size();
        n = grid[0].size();

        memo.assign(m, vector<array<int,2>>(n));

        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                memo[i][j] = {-2, -2};

        vector<vector<long long>> dp(m, vector<long long>(n));
        dp[0][0] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] || dp[i][j] == 0)
                    continue;

                long long ways = dp[i][j];

                if (j + 1 < n) {
                    int x = jump(i, j + 1, 0);
                    if (x != -1) {
                        int r = x / n, c = x % n;
                        dp[r][c] = (dp[r][c] + ways) % MOD;
                    }
                }

                if (i + 1 < m) {
                    int x = jump(i + 1, j, 1);
                    if (x != -1) {
                        int r = x / n, c = x % n;
                        dp[r][c] = (dp[r][c] + ways) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};