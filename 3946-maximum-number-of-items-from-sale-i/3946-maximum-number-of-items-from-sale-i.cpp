class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int freq[1501] = {}, gain[1501] = {};
        int minPrice = INT_MAX;

        for (auto& x : items) {
            freq[x[0]]++;
            minPrice = min(minPrice, x[1]);
        }

        for (int f = 1; f <= 1500; f++) {
            for (int x = f; x <= 1500; x += f) {
                gain[f] += freq[x];
            }
        }

        const int NEG = -1e9;
        vector<int> dp(budget + 1, NEG);
        dp[0] = 0;

        for (auto& x : items) {
            int f = x[0], p = x[1];

            for (int j = budget; j >= p; j--) {
                if (dp[j - p] != NEG) {
                    dp[j] = max(dp[j], dp[j - p] + gain[f]);
                }
            }
        }

        int ans = 0;

        for (int j = 0; j <= budget; j++) {
            if (dp[j] != NEG) {
                ans = max(ans, dp[j] + (budget - j) / minPrice);
            }
        }

        return ans;
    }
};