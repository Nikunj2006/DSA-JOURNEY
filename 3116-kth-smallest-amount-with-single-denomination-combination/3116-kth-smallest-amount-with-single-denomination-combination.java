class Solution {

    // Greatest Common Divisor
    private long gcd(long a, long b) {
        while (b != 0) {
            long temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    // Least Common Multiple
    private long lcm(long a, long b, long limit) {
        long g = gcd(a, b);

        long result = a / g;

        // Prevent overflow
        if (result > limit / b) {
            return limit + 1;
        }

        result *= b;

        if (result > limit) {
            return limit + 1;
        }

        return result;
    }

    // Count how many valid amounts are <= x
    private long count(long x, int[] coins) {

        int n = coins.length;
        long count = 0;

        // Every non-empty subset of coins
        for (int mask = 1; mask < (1 << n); mask++) {

            long multiple = 1;
            int bits = 0;
            boolean tooLarge = false;

            for (int i = 0; i < n; i++) {

                if ((mask & (1 << i)) != 0) {

                    bits++;

                    multiple = lcm(
                        multiple,
                        coins[i],
                        x
                    );

                    if (multiple > x) {
                        tooLarge = true;
                        break;
                    }
                }
            }

            if (tooLarge) {
                continue;
            }

            long ways = x / multiple;

            // Odd number of coins -> add
            // Even number of coins -> subtract
            if (bits % 2 == 1) {
                count += ways;
            } else {
                count -= ways;
            }
        }

        return count;
    }

    public long findKthSmallest(int[] coins, int k) {

        long low = 1;

        // The answer cannot be greater than
        // smallest coin * k
        long minCoin = coins[0];

        for (int coin : coins) {
            minCoin = Math.min(minCoin, coin);
        }

        long high = minCoin * (long) k;

        // Binary search
        while (low < high) {

            long mid = low + (high - low) / 2;

            if (count(mid, coins) >= k) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
}