class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> cnt(26, 0);
        for (char c : s) cnt[c - 'a']++;
        int matched = 0;
        while (matched < n && cnt[target[matched] - 'a'] > 0) {
            cnt[target[matched] - 'a']--;
            matched++;
        }
        for (int pos = min(matched, n - 1); pos >= 0; pos--) {
            if (pos < matched) cnt[target[pos] - 'a']++;
            for (int c = target[pos] - 'a' + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    cnt[c]--;
                    string res = target.substr(0, pos) + char('a' + c);
                    for (int x = 0; x < 26; x++)
                        while (cnt[x]--) res += char('a' + x);
                    return res;
                }
            }
        }
        return "";
    }
};   