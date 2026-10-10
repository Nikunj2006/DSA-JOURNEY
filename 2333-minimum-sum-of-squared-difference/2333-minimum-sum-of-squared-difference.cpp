class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<long long> d(n);
        long long mx = 0;

        for (int i = 0; i < n; i++) {
            d[i] = abs((long long)nums1[i] - nums2[i]);
            mx = max(mx, d[i]);
        }

        auto need = [&](long long x) {
            long long res = 0;
            for (long long v : d) {
                if (v > x) {
                    res += v - x;
                    if (res > k) return res;
                }
            }
            return res;
        };

        long long lo = 0, hi = mx;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (need(mid) <= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        long long level = lo;
        long long used = need(level);
        long long rem = k - used;

        for (long long &x : d)
            if (x > level)
                x = level;

        for (long long &x : d) {
            if (rem == 0) break;
            if (x == level && x > 0) {
                x--;
                rem--;
            }
        }

        long long ans = 0;

        for (long long x : d)
            ans += x * x;

        return ans;
    }
};