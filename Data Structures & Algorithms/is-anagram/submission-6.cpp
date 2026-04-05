class Solution {
public:
    bool isAnagram(string s, string t) {
        int sizeS = s.size();
        int sizeT = t.size();
        unordered_map<char, int> myHashS;
        unordered_map<char, int> myHashT;

        if (sizeS != sizeT) {
            return false;
        }

        for (int i = 0; i< sizeS; i++) {
            myHashS[s[i]]++;
            myHashT[t[i]]++;
        }

        for (char ch: s) {
            if (myHashS[ch] != myHashT[ch]) {
                return false;
            }
        }

        return true;
    }
};
