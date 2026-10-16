class Solution {
public:
    static const long long MOD = 1000000007;

    struct Node {
        long long sum = 0;
        long long sq = 0;
        long long lazy = 0;
    };

    vector<Node> st;

    void push(int p, int l, int r) {
        if (!st[p].lazy || l == r) return;

        long long x = st[p].lazy;
        int m = (l + r) / 2;

        for (int c : {p * 2, p * 2 + 1}) {
            long long len = (c == p * 2 ? m - l + 1 : r - m);
            st[c].sq = (st[c].sq + 2 * x % MOD * st[c].sum + x * x % MOD * len) % MOD;
            st[c].sum = (st[c].sum + x * len) % MOD;
            st[c].lazy = (st[c].lazy + x) % MOD;
        }

        st[p].lazy = 0;
    }

    void add(int p, int l, int r, int ql, int qr) {
        if (ql > r || qr < l) return;

        if (ql <= l && r <= qr) {
            long long x = 1;
            long long len = r - l + 1;

            st[p].sq = (st[p].sq + 2 * x % MOD * st[p].sum + x * x % MOD * len) % MOD;
            st[p].sum = (st[p].sum + len) % MOD;
            st[p].lazy = (st[p].lazy + 1) % MOD;
            return;
        }

        push(p, l, r);

        int m = (l + r) / 2;
        add(p * 2, l, m, ql, qr);
        add(p * 2 + 1, m + 1, r, ql, qr);

        st[p].sum = (st[p * 2].sum + st[p * 2 + 1].sum) % MOD;
        st[p].sq = (st[p * 2].sq + st[p * 2 + 1].sq) % MOD;
    }

    long long sumCounts(vector<int>& nums) {
        int n = nums.size();
        st.resize(4 * n + 5);

        vector<int> last(100001, -1);
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int p = last[nums[r]];
            add(1, 0, n - 1, p + 1, r);
            last[nums[r]] = r;

            ans = (ans + st[1].sq) % MOD;
        }

        return ans;
    }
};