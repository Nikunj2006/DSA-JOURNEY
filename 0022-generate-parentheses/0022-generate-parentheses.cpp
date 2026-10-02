class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s;

        function<void(int,int)> dfs = [&](int open, int close) {
            if (s.size() == 2 * n) {
                ans.push_back(s);
                return;
            }

            if (open < n) {
                s.push_back('(');
                dfs(open + 1, close);
                s.pop_back();
            }

            if (close < open) {
                s.push_back(')');
                dfs(open, close + 1);
                s.pop_back();
            }
        };

        dfs(0, 0);
        return ans;
    }
};