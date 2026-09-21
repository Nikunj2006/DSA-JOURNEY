class Solution:
    def stoneGameIX(self, stones):
        cnt = [0, 0, 0]
        for x in stones:
            cnt[x % 3] += 1

        a, b, z = cnt[1], cnt[2], cnt[0]

        if a == 0 and b == 0:
            return False

        if z % 2 == 0:
            return a > 0 and b > 0

        return abs(a - b) > 2