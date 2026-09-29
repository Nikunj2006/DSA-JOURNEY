class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if ((m + n) % 2 == 0 || grid[0][0] == ')' ||
            grid[m-1][n-1] == '(')
            return false;

        vector<vector<vector<bool>>> dp(
            m, vector<vector<bool>>(n, vector<bool>(m+n+1, false))
        );

        dp[0][0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) continue;

                for (int b = 0; b <= m+n; b++) {
                    if (i > 0 && dp[i-1][j][b]) {
                        int nb = b + (grid[i][j] == '(' ? 1 : -1);
                        if (nb >= 0) dp[i][j][nb] = true;
                    }

                    if (j > 0 && dp[i][j-1][b]) {
                        int nb = b + (grid[i][j] == '(' ? 1 : -1);
                        if (nb >= 0) dp[i][j][nb] = true;
                    }
                }
            }
        }

        return dp[m-1][n-1][0];
    }
};