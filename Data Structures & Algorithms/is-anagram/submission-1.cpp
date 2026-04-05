class Solution {
public:
    bool isAnagram(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        if (s.length() != t.length()) {
            return false;
        }

        for (char c = 0; c < s.length(); c++) {
            if (s[c] != t[c]) {
                return false;
            }
        }
        return true;
    }
};
