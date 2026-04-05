#include<string>
#include<cstring>
class Solution {
public:
    int t[1001][1001];
    int solve(string s, int i, int j) {
        if (i >= j) {
            return true;
        }
        if (t[i][j] != -1) return t[i][j];
        if (s[i] == s[j]) return t[i][j]=solve(s, i+1, j-1);
        return t[i][j] = 0;
    }
    string longestPalindrome(string s) {
        int n = s.length();
        memset(t, -1, sizeof(t));
        int maxLength = INT_MIN;
        int sp = -1;

        for (int i = 0; i<n; i++) {
            for (int j = i; j<n; j++) {
                if (solve(s, i, j)) {
                    if (j-i+1 > maxLength) {
                        maxLength = j-i+1;
                        sp = i;
                    }
                }
            }
        }

        return s.substr(sp, maxLength);
    }
};
