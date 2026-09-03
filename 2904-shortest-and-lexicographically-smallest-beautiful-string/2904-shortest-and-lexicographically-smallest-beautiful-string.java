class Solution {
    public String shortestBeautifulSubstring(String s, int k) {
        int n = s.length();
        String best = "";
        int bestLen = Integer.MAX_VALUE;

        for (int i = 0; i < n; i++) {
            int ones = 0;
            for (int j = i; j < n; j++) {
                if (s.charAt(j) == '1') ones++;
                if (ones > k) break;
                if (ones == k) {
                    int len = j - i + 1;
                    if (len < bestLen) {
                        bestLen = len;
                        best = s.substring(i, j + 1);
                    } else if (len == bestLen) {
                        String cur = s.substring(i, j + 1);
                        if (cur.compareTo(best) < 0) best = cur;
                    }
                }
            }
        }
        return best;
    }
}   