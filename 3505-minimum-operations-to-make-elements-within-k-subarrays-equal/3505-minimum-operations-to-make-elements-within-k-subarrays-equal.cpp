
class Solution {
public:
    multiset<long long> left, right;
    long long sumL = 0, sumR = 0;

    void balance() {
        while (left.size() > right.size() + 1) {
            auto it = prev(left.end());
            long long val = *it;
            left.erase(it);
            sumL -= val;
            right.insert(val);
            sumR += val;
        }

        while (left.size() < right.size()) {
            auto it = right.begin();
            long long val = *it;
            right.erase(it);
            sumR -= val;
            left.insert(val);
            sumL += val;
        }
    }

    void add(long long val) {
        if (left.empty() || val <= *left.rbegin()) {
            left.insert(val);
            sumL += val;
        } else {
            right.insert(val);
            sumR += val;
        }
        balance();
    }

    void remove(long long val) {
        auto it = left.find(val);

        if (it != left.end()) {
            left.erase(it);
            sumL -= val;
        } else {
            it = right.find(val);
            right.erase(it);
            sumR -= val;
        }

        balance();
    }

    long long getCost() {
        long long med = *left.rbegin();

        return med * (long long)left.size() - sumL
             + sumR - med * (long long)right.size();
    }

    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();

        vector<long long> cost(n - x + 1);

        for (int i = 0; i < n; i++) {
            add(nums[i]);

            if (i >= x) {
                remove(nums[i - x]);
            }

            if (i >= x - 1) {
                cost[i - x + 1] = getCost();
            }
        }

        const long long INF = 1e18;

        vector<vector<long long>> dp(
            k + 1, vector<long long>(n + 1, INF)
        );

        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }

        for (int j = 1; j <= k; j++) {
            for (int i = j * x; i <= n; i++) {

                dp[j][i] = dp[j][i - 1];

                dp[j][i] = min(
                    dp[j][i],
                    dp[j - 1][i - x] + cost[i - x]
                );
            }
        }

        return dp[k][n];
    }
};
