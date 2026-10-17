class Solution {
public:
    int digitSum(int x) {
        int s = 0;
        while (x) {
            s += x % 10;
            x /= 10;
        }
        return s;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<pair<int,int>, int>> a;

        for (int i = 0; i < n; i++)
            a.push_back({{digitSum(nums[i]), nums[i]}, i});

        sort(a.begin(), a.end());

        vector<int> pos(n);
        for (int i = 0; i < n; i++)
            pos[a[i].second] = i;

        vector<bool> vis(n, false);
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (vis[i] || pos[i] == i)
                continue;

            int j = i, cycle = 0;

            while (!vis[j]) {
                vis[j] = true;
                j = pos[j];
                cycle++;
            }

            ans += cycle - 1;
        }

        return ans;
    }
};