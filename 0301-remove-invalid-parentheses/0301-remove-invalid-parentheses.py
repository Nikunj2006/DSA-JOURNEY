class Solution:
    def removeInvalidParentheses(self, s: str) -> list[str]:
        left_rem = right_rem = 0
        for c in s:
            if c == '(':
                left_rem += 1
            elif c == ')':
                if left_rem > 0:
                    left_rem -= 1
                else:
                    right_rem += 1

        result = set()

        def dfs(i, left_rem, right_rem, left_count, right_count, cur):
            if i == len(s):
                if left_rem == 0 and right_rem == 0:
                    result.add(cur)
                return
            if len(s) - i < left_rem + right_rem or left_count < right_count:
                return
            c = s[i]
            if c == '(' and left_rem > 0:
                dfs(i + 1, left_rem - 1, right_rem, left_count, right_count, cur)
            if c == ')' and right_rem > 0:
                dfs(i + 1, left_rem, right_rem - 1, left_count, right_count, cur)
            
            dfs(i + 1, left_rem, right_rem,
                left_count + (c == '('), right_count + (c == ')'), cur + c)

        dfs(0, left_rem, right_rem, 0, 0, "")
        return list(result)   