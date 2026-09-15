class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();

        // g[i][j] = true if s[i..j] is a palindrome
        vector<vector<bool>> g(n, vector<bool>(n, true));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = (s[i] == s[j] && g[i + 1][j - 1]);
            }
        }

        // f[i] = max # of non-overlapping palindromes from index i onward
        vector<int> f(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            f[i] = f[i + 1]; // skip s[i]
            for (int j = i + k - 1; j < n; ++j) {
                if (g[i][j]) {
                    f[i] = max(f[i], 1 + f[j + 1]);
                }
            }
        }
        return f[0];
    }
};   