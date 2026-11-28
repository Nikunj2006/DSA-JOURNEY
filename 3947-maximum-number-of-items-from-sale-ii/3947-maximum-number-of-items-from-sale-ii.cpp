class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);

        long long minPrice = LLONG_MAX;

        for (auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, (long long)item[1]);
        }

        // eligible[f] = number of item types whose factor is divisible by f
        vector<int> eligible(n + 1, 0);

        for (int f = 1; f <= n; f++) {
            for (int multiple = f; multiple <= n; multiple += f) {
                eligible[f] += freq[multiple];
            }
        }

        vector<pair<long long, long long>> bonus;

        for (auto& item : items) {
            int factor = item[0];
            long long price = item[1];

            long long freeLimit = eligible[factor] - 1;

            if (freeLimit > 0 && price < 2 * minPrice) {
                bonus.push_back({price, freeLimit});
            }
        }

        sort(bonus.begin(), bonus.end());

        long long spent = 0;
        long long bonusCount = 0;

        for (auto [price, limit] : bonus) {
            long long take = min(limit, (budget - spent) / price);
            spent += take * price;
            bonusCount += take;
        }

        long long answer = 2 * bonusCount + (budget - spent) / minPrice;
        return (int)answer;
    }
};