class Solution:
    def sumGame(self, num: str) -> bool:
        n = len(num)
        mid = n // 2
        
        s1 = s2 = 0
        cnt1 = cnt2 = 0
        
        for i in range(mid):
            if num[i] == '?':
                cnt1 += 1
            else:
                s1 += int(num[i])
        
        for i in range(mid, n):
            if num[i] == '?':
                cnt2 += 1
            else:
                s2 += int(num[i])
        
        total_q = cnt1 + cnt2
        
        # Alice wins if total '?' is odd (she gets last move)
        # or if the sum difference can't be exactly balanced
        if total_q % 2 == 1:
            return True
        
        return s1 - s2 != 9 * (cnt2 - cnt1) // 2   