class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const long long MOD = 1000000007;
        vector<long long> ans(k, 0);
        vector<int> cnt(31, 0);

        for (int x : nums) {
            for (int b = 0; b <= 30; b++) {
                if (x & (1 << b))
                    cnt[b]++;
            }
        }

        for (int b = 30; b >= 0; b--) {
            for (int i = 0; i < k && cnt[b] > 0; i++) {
                if (!(ans[i] & (1LL << b))) {
                    ans[i] |= (1LL << b);
                    cnt[b]--;
                }
            }
        }

        long long res = 0;
        for (long long x : ans)
            res = (res + x * x) % MOD;

        return res;
    }
};