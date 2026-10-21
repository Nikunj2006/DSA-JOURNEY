class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string t = s;
        sort(t.begin(), t.end());

        if (s == t)
            return 0;

        if (n == 2)
            return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        if (s[0] == mx && s[n - 1] == mn) {
            int cmn = count(s.begin(), s.end(), mn);
            int cmx = count(s.begin(), s.end(), mx);

            if (cmn > 1 || cmx > 1)
                return 2;

            return 3;
        }

        return 2;
    }
};