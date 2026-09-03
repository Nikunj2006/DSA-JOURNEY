class Solution {
    public boolean checkDivisibility(int n) {

        int temp = n;

        int sum = 0;
        int product = 1;

        while (temp > 0) {

            int digit = temp % 10;  // get last digit

            sum += digit;           // digit sum
            product *= digit;       // digit product

            temp /= 10;             // remove last digit
        }

        int total = sum + product;

        return n % total == 0;
    }
}