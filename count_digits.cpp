/*
 * Count the digits of an integer
 * ---------------------------------------------------------------
 * PROBLEM:
 *   Given an integer n, return how many digits it has.
 *   e.g. 12345 -> 5,  7 -> 1,  0 -> 1,  -99 -> 2
 *
 * IDEA:
 *   n % 10 gives the LAST digit, n / 10 removes it (integer division).
 *   So: remove one digit at a time and count how many removals it takes
 *   to reach 0.
 *
 * DRY RUN: n = 4072
 *   4072 -> cnt=1, n=407
 *    407 -> cnt=2, n=40
 *     40 -> cnt=3, n=4
 *      4 -> cnt=4, n=0  -> loop ends, return 4
 *
 * EDGE CASES HANDLED:
 *   - n == 0 : the loop condition (x > 0) is false immediately, so the loop
 *              would count 0 digits. But "0" is one digit, so special-case it.
 *   - n < 0  : the sign is not a digit, so work with the absolute value.
 *   - INT_MIN: -INT_MIN doesn't fit in an int (overflow), so we copy n into
 *              a `long long` BEFORE negating.
 *
 * COMPLEXITY:
 *   Time  : O(d), d = number of digits (~ log10(n))
 *   Space : O(1)
 */

int countDigits(int n) {
    if (n == 0) return 1;           // special case, explained above

    long long x = n;                // wider type so negating INT_MIN is safe
    if (x < 0) x = -x;              // ignore the minus sign

    int cnt = 0;
    while (x > 0) {
        cnt++;                      // one more digit found
        x /= 10;                    // chop off the last digit
    }
    return cnt;
}

/*
 * ALTERNATIVE: O(1) using logarithms (only valid for n > 0)
 *
 *   #include <cmath>
 *   int cnt = (int)log10(n) + 1;
 *
 * Why it works: log10(n) is roughly "the power of 10 just below n".
 *   log10(1000) = 3 -> 3 + 1 = 4 digits.   log10(999) = 2.99.. -> 2 + 1 = 3 digits.
 *
 * Why the loop is still the safer default:
 *   - log10(0) is undefined (negative infinity).
 *   - It uses floating point, so precision errors can give a wrong answer
 *     for large values.
 */