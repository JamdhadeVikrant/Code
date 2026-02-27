class Solution {
public:
    int minOperations(string s, int k) {
        long long n = (long long)s.size();
        long long z = 0;
        for (char c : s) z += (c == '0');
        if (z == 0) return 0;

        if (k == (int)n) return (z == n) ? 1 : -1;

        // If k is even, parity of zeros can't change -> must start with even zeros to reach 0
        if ((k % 2 == 0) && (z % 2 == 1)) return -1;

        auto ok = [&](long long t) -> bool {
            long long total = t * (long long)k;
            if ( (total & 1LL) != (z & 1LL) ) return false;

            long long oddMax  = (t & 1LL) ? t : (t - 1);
            long long evenMax = (t & 1LL) ? (t - 1) : t;
            if (oddMax < 1) return false;

            long long o = n - z;

            long long L = max(z, total - o * evenMax);
            long long R = min(z * oddMax, total);
            if (L > R) return false;

            if ( (L & 1LL) != (z & 1LL) ) L++;
            return L <= R;
        };

        long long t = (z + k - 1LL) / k;
        if (t < 1) t = 1;

        long long upper = 2 * n + 5;

        if (k % 2 == 1) {
            if ((t & 1LL) != (z & 1LL)) t++;
            for (; t <= upper; t += 2) if (ok(t)) return (int)t;
        } else {
            for (; t <= upper; t++) if (ok(t)) return (int)t;
        }

        return -1;
    }
};
/*You are given a binary string s, and an integer k.

In one operation, you must choose exactly k different indices and flip each '0' to '1' and each '1' to '0'.

Return the minimum number of operations required to make all characters in the string equal to '1'. If it is not possible, return -1.

 

Example 1:

Input: s = "110", k = 1

Output: 1

Explanation:

There is one '0' in s.
Since k = 1, we can flip it directly in one operation.
Example 2:

Input: s = "0101", k = 3

Output: 2

Explanation:

One optimal set of operations choosing k = 3 indices in each operation is:

Operation 1: Flip indices [0, 1, 3]. s changes from "0101" to "1000".
Operation 2: Flip indices [1, 2, 3]. s changes from "1000" to "1111".
Thus, the minimum number of operations is 2.

Example 3:

Input: s = "101", k = 2

Output: -1

Explanation:

Since k = 2 and s has only one '0', it is impossible to flip exactly k indices to make all '1'. Hence, the answer is -1.

 

Constraints:

1 <= s.length <= 10​​​​​​​5
s[i] is either '0' or '1'.
1 <= k <= s.length*/