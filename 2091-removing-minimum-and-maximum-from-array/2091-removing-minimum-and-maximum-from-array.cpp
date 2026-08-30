class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size(), mi = 0, mx = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < nums[mi]) mi = i;
            if (nums[i] > nums[mx]) mx = i;
        }
        if (mi > mx) swap(mi, mx);
        return min({mx + 1, n - mi, mi + 1 + n - mx});
    }
};   