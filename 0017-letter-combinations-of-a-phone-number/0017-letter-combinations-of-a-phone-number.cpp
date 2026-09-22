#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;

    void backtrack(string digits, int index, string curr, vector<string>& mapping) {
        if (index == digits.size()) {
            result.push_back(curr);
            return;
        }

        string letters = mapping[digits[index] - '0'];

        for (char c : letters) {
            backtrack(digits, index + 1, curr + c, mapping);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi", "jkl",
            "mno", "pqrs", "tuv", "wxyz"
        };

        backtrack(digits, 0, "", mapping);
        return result;
    }
};