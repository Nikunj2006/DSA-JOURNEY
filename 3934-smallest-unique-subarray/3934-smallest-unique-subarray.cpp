class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();

        vector<int> vals = nums;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<int> sa(n), rank(n), nr(n);
        iota(sa.begin(), sa.end(), 0);

        for (int i = 0; i < n; i++) {
            rank[i] = lower_bound(vals.begin(), vals.end(), nums[i]) - vals.begin();
        }

        for (int len = 1; len < n; len *= 2) {
            sort(sa.begin(), sa.end(), [&](int a, int b) {
                if (rank[a] != rank[b])
                    return rank[a] < rank[b];

                int x = a + len < n ? rank[a + len] : -1;
                int y = b + len < n ? rank[b + len] : -1;

                return x < y;
            });

            int r = 0;
            nr[sa[0]] = 0;

            for (int i = 1; i < n; i++) {
                int a = sa[i - 1], b = sa[i];

                if (rank[a] != rank[b] ||
                    (a + len < n ? rank[a + len] : -1) !=
                    (b + len < n ? rank[b + len] : -1)) {
                    r++;
                }

                nr[b] = r;
            }

            rank.swap(nr);

            if (r == n - 1) break;
        }

        vector<int> lcp(n, 0);
        int h = 0;

        for (int i = 0; i < n; i++) {
            int r = rank[i];

            if (r == 0) {
                h = 0;
                continue;
            }

            int j = sa[r - 1];

            while (i + h < n && j + h < n &&
                   nums[i + h] == nums[j + h]) {
                h++;
            }

            lcp[r] = h;
            if (h > 0) h--;
        }

        int ans = n;

        for (int r = 0; r < n; r++) {
            int i = sa[r];

            int longestMatch = max(
                lcp[r],
                r + 1 < n ? lcp[r + 1] : 0
            );

            if (longestMatch < n - i) {
                ans = min(ans, longestMatch + 1);
            }
        }

        return ans;
    }
};