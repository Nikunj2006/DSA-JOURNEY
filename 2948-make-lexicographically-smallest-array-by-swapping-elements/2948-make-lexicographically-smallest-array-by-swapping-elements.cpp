class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> arr(n);
        for (int i = 0; i < n; i++) arr[i] = {nums[i], i};
        sort(arr.begin(), arr.end());

        vector<int> res(n);
        int i = 0;
        while (i < n) {
            int j = i;
            while (j + 1 < n && arr[j+1].first - arr[j].first <= limit) j++;
            vector<int> idx;
            for (int k = i; k <= j; k++) idx.push_back(arr[k].second);
            sort(idx.begin(), idx.end());
            for (int k = 0; k <= j - i; k++)
                res[idx[k]] = arr[i + k].first;
            i = j + 1;
        }
        return res;
    }
};   