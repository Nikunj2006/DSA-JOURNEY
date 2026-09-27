class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> last(26), used(26, 0);
        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        string ans;
        for (int i = 0; i < s.size(); i++) {
            int c = s[i] - 'a';
            if (used[c]) continue;

            while (!ans.empty() && ans.back() > s[i] &&
                   last[ans.back() - 'a'] > i) {
                used[ans.back() - 'a'] = 0;
                ans.pop_back();
            }

            ans += s[i];
            used[c] = 1;
        }
        return ans;
    }
};