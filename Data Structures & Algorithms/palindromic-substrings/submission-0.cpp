class Solution {
public:
    bool isPalindrom(string s, int i, int j) {
        if (i>=j) return true;

        if (s[i] == s[j]) {
            return isPalindrom(s,i+1,j-1);
        }
        return false;
    }
    int countSubstrings(string s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i<n; i++) {
            for (int j = i; j<n;j++) {
                if (isPalindrom(s,i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};
