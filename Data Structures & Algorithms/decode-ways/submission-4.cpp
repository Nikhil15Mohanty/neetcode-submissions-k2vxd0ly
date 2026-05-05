#include<cstring>
class Solution {
public:
    int t[101];
    int countDecodeWays(string s, int i, int n) {
        if (i == n) {
            return t[i] = 1;
        }

        if (t[i] != -1) return t[i];
        if (s[i] == '0') return 0;

        int result = countDecodeWays(s, i+1, n);

        if (i+1<n) {
            if (s[i] == '1' || s[i] == '2' && s[i+1] <='6') {
                result += countDecodeWays(s, i+2, n);
            }
        }
        return t[i]=result;
    }
    int numDecodings(string s) {
        memset(t, -1, sizeof(t));
        int n = s.length();
        return countDecodeWays(s, 0, n);
    }
};
