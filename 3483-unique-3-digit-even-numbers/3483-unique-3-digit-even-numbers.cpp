class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;
        int n = digits.size();
        for (int i = 0; i < n; ++i) {          // units digit (must be even)
            if (digits[i] % 2 == 1) continue;
            for (int j = 0; j < n; ++j) {      // tens digit
                if (i == j) continue;
                for (int k = 0; k < n; ++k) {  // hundreds digit (non-zero)
                    if (digits[k] == 0 || k == i || k == j) continue;
                    s.insert(digits[k] * 100 + digits[j] * 10 + digits[i]);
                }
            }
        }
        return s.size();
    }
};   