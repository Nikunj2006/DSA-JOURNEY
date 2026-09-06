class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.size(), n = t.size();
        const int CAP = INT_MAX;
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;

        for (int i = 0; i < m; i++)
            for (int j = n; j >= 1; j--)
                if (s[i] == t[j - 1]) {
                    dp[j] += dp[j - 1];
                    if (dp[j] > CAP) dp[j] = CAP;
                }

        return (int)dp[n];
    }
};   