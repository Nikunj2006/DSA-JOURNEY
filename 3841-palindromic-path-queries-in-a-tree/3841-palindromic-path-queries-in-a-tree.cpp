class Solution {
public:
    int n, timer;
    vector<vector<int>> g;
    vector<int> parent, depth, heavy, sz, head, pos;
    vector<int> seg;
    string s;

    int dfs(int u, int p) {
        parent[u] = p;
        sz[u] = 1;
        int mx = 0;

        for (int v : g[u]) {
            if (v == p) continue;

            depth[v] = depth[u] + 1;
            int sub = dfs(v, u);
            sz[u] += sub;

            if (sub > mx) {
                mx = sub;
                heavy[u] = v;
            }
        }

        return sz[u];
    }

    void decompose(int u, int h) {
        head[u] = h;
        pos[u] = timer++;

        if (heavy[u] != -1)
            decompose(heavy[u], h);

        for (int v : g[u]) {
            if (v == parent[u] || v == heavy[u])
                continue;
            decompose(v, v);
        }
    }

    void update(int p, int l, int r, int idx, int val) {
        if (l == r) {
            seg[p] = val;
            return;
        }

        int m = (l + r) / 2;

        if (idx <= m)
            update(p * 2, l, m, idx, val);
        else
            update(p * 2 + 1, m + 1, r, idx, val);

        seg[p] = seg[p * 2] ^ seg[p * 2 + 1];
    }

    int query(int p, int l, int r, int ql, int qr) {
        if (ql <= l && r <= qr)
            return seg[p];

        int m = (l + r) / 2;
        int ans = 0;

        if (ql <= m)
            ans ^= query(p * 2, l, m, ql, qr);

        if (qr > m)
            ans ^= query(p * 2 + 1, m + 1, r, ql, qr);

        return ans;
    }

    int pathQuery(int u, int v) {
        int ans = 0;

        while (head[u] != head[v]) {
            if (depth[head[u]] < depth[head[v]])
                swap(u, v);

            ans ^= query(1, 0, n - 1, pos[head[u]], pos[u]);
            u = parent[head[u]];
        }

        if (depth[u] > depth[v])
            swap(u, v);

        ans ^= query(1, 0, n - 1, pos[u], pos[v]);

        return ans;
    }

    vector<bool> palindromePath(int n, vector<vector<int>>& edges,
                                string s, vector<string>& queries) {
        this->n = n;
        this->s = s;

        g.assign(n, {});
        for (auto &e : edges) {
            g[e[0]].push_back(e[1]);
            g[e[1]].push_back(e[0]);
        }

        parent.assign(n, -1);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        sz.assign(n, 0);
        head.assign(n, 0);
        pos.assign(n, 0);

        dfs(0, -1);

        timer = 0;
        decompose(0, 0);

        seg.assign(4 * n, 0);

        for (int i = 0; i < n; i++)
            update(1, 0, n - 1, pos[i], 1 << (s[i] - 'a'));

        vector<bool> ans;

        for (string &q : queries) {
            string type;
            stringstream ss(q);
            ss >> type;

            if (type == "update") {
                int u;
                char c;
                ss >> u >> c;

                s[u] = c;
                update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else {
                int u, v;
                ss >> u >> v;

                int mask = pathQuery(u, v);

                ans.push_back(__builtin_popcount(mask) <= 1);
            }
        }

        return ans;
    }
};