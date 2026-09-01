class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size(), n = classroom[0].size();
        int d[20][20] = {};
        int sx = 0, sy = 0, cnt = 0;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++) {
                if (classroom[i][j] == 'S') { sx = i; sy = j; }
                else if (classroom[i][j] == 'L') { d[i][j] = cnt++; }
            }
        if (cnt == 0) return 0;

        int full = (1 << cnt) - 1;
        // vis[i][j][e][mask]
        vector<vector<vector<vector<bool>>>> vis(m, vector<vector<vector<bool>>>(n,
            vector<vector<bool>>(energy + 1, vector<bool>(1 << cnt, false))));

        queue<tuple<int,int,int,int>> q;
        q.push({sx, sy, energy, full});
        vis[sx][sy][energy][full] = true;
        int dirs[5] = {-1, 0, 1, 0, -1};
        int ans = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int s = 0; s < sz; s++) {
                auto [i, j, curE, mask] = q.front(); q.pop();
                if (mask == 0) return ans;
                if (curE <= 0) continue;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dirs[k], nj = j + dirs[k+1];
                    if (ni < 0 || ni >= m || nj < 0 || nj >= n) continue;
                    char c = classroom[ni][nj];
                    if (c == 'X') continue;
                    int ne = (c == 'R') ? energy : curE - 1;
                    int nm = mask;
                    if (c == 'L') nm &= ~(1 << d[ni][nj]);
                    if (!vis[ni][nj][ne][nm]) {
                        vis[ni][nj][ne][nm] = true;
                        q.push({ni, nj, ne, nm});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};   