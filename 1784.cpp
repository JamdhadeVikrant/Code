class Solution {
public:
    bool checkOnesSegment(string& s) {
        const int n=s.size();
        int i0=0;
        while(s[i0]=='1') i0++;
        if (i0==n) return 1;
        int i1=n-1;
        while(s[i1]=='0') i1--;
        return i0>i1;
    }
};
/*Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

 

Example 1:

Input: s = "1001"
Output: false
Explanation: The ones do not form a contiguous segment.
Example 2:

Input: s = "110"
Output: true
 

Constraints:

1 <= s.length <= 100
s[i]​​​​ is either '0' or '1'.
s[0] is '1'.*/