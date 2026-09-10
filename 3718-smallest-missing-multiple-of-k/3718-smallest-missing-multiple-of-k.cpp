class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        for (int i = k; ; i += k)
            if (!s.count(i)) return i;
        return -1;
    }
};   