class Solution {
public:
    bool isRotation(vector<int>& a, int l, int k, vector<int>& sorted) {
        int m = 0;

        for (int i = 0; i < k * 2 - 1; i++) {
            int x = sorted[l + (i % k)];

            while (m > 0 && a[l + i % k] != a[l + m])
                m--;

            if (a[l + i % k] == a[l + m])
                m++;

            if (m == k)
                return true;
        }

        return false;
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0)
                continue;

            bool ok = true;

            for (int l = 0; l < n; l += k) {
                vector<int> block(nums.begin() + l, nums.begin() + l + k);
                vector<int> target(sorted.begin() + l, sorted.begin() + l + k);

                bool found = false;

                for (int shift = 0; shift < k; shift++) {
                    bool same = true;

                    for (int j = 0; j < k; j++) {
                        if (block[j] != target[(j + shift) % k]) {
                            same = false;
                            break;
                        }
                    }

                    if (same) {
                        found = true;
                        break;
                    }
                }

                if (!found) {
                    ok = false;
                    break;
                }
            }

            if (ok)
                ans += k;
        }

        return ans;
    }
};