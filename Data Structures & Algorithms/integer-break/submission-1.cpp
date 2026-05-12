#include<bits/stdc++.h>
class Solution {
public:
    int t[59];
    int solve(int n) {
        if (n == 1) return 1;
        if (n < 0) return 0;

        if (t[n]!=-1) return t[n];

        int maxValue = -1;
        for (int i = 1; i<n; i++) {
            maxValue = max(maxValue, max(i*(n-i), i * solve(n-i)));
        }
        return t[n] = maxValue;
    }
    int integerBreak(int n) {
        memset(t, -1, sizeof(t));
        return solve(n);
    }
};