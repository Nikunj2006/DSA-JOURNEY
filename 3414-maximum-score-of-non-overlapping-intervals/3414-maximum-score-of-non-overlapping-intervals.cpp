class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<array<int,4>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({intervals[i][0], intervals[i][1], intervals[i][2], i});
        sort(arr.begin(), arr.end());

        vector<int> starts(n);
        for (int i = 0; i < n; i++) starts[i] = arr[i][0];

        vector<vector<pair<long long, vector<int>>>> memo(n+1, vector<pair<long long, vector<int>>>(5));
        vector<vector<bool>> vis(n+1, vector<bool>(5, false));

        function<pair<long long, vector<int>>(int, int)> dp = [&](int i, int quota) -> pair<long long, vector<int>> {
            if (i >= n || quota == 0) return {0, {}};
            if (vis[i][quota]) return memo[i][quota];
            vis[i][quota] = true;

            // Skip
            auto [skip_w, skip_sel] = dp(i + 1, quota);

            // Pick
            int r = arr[i][1], w = arr[i][2], orig = arr[i][3];
            int j = upper_bound(starts.begin(), starts.end(), r) - starts.begin();
            auto [next_w, next_sel] = dp(j, quota - 1);

            long long pick_w = (long long)w + next_w;
            vector<int> pick_sel = next_sel;
            pick_sel.push_back(orig);
            sort(pick_sel.begin(), pick_sel.end());

            pair<long long, vector<int>> res;
            if (pick_w > skip_w || (pick_w == skip_w && pick_sel < skip_sel))
                res = {pick_w, pick_sel};
            else
                res = {skip_w, skip_sel};

            memo[i][quota] = res;
            return res;
        };

        return dp(0, 4).second;
    }
};   