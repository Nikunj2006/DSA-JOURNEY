class Solution {
    private static final int MOD = (int) 1e9 + 7;

    public int distinctSubseqII(String s) {
        int[] dp = new int[26];
        int total = 0;
        for (char c : s.toCharArray()) {
            int j = c - 'a';
            int add = (total - dp[j] + 1 + MOD) % MOD;
            total = (total + add) % MOD;
            dp[j] = (dp[j] + add) % MOD;
        }
        return total;
    }
}   