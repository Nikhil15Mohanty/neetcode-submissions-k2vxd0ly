class Solution {
public:
    int ispalidrome(string s, int i, int j) {
        if (i>=j) return 1;
        if (s[i] == s[j]) return ispalidrome(s, i+1, j-1);
        return 0;
    }
    int countSubstrings(string s) {
        int length = s.length();
        int count = 0;

        for (int i = 0; i<length; i++) {
            for (int j = i; j<length; j++) {
                if (ispalidrome(s,i,j)) {
                    count += 1;
                }
            }
        }

        return count;
    }
};
