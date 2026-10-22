class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int pos0 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos0 = i;
                break;
            }
        }

        bool is_inc = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(pos0 + i) % n] != i) {
                is_inc = false;
                break;
            }
        }

        bool is_dec = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(pos0 - i + n) % n] != i) {
                is_dec = false;
                break;
            }
        }

        if (!is_inc && !is_dec) return -1;

        int ans = INT_MAX;
        if (is_inc) {
            ans = min(ans, pos0);
            ans = min(ans, (n - pos0) + 2);
        }
        if (is_dec) {
            ans = min(ans, 1 + (n - 1 - pos0));
            ans = min(ans, ((pos0 + 1) % n) + 1);
        }

        return ans;
    }
};