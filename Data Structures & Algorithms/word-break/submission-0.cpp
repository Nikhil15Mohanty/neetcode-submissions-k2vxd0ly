#include<cstring>
class Solution {
public:
    unordered_set<string> st;
    int n;
    int t[301];

    bool solve(string &s, int index) {
        if (index==n) return true;
        if(st.find(s.substr(index, n - index)) != st.end()) return true;
        if(t[index] != -1) return t[index];

        for (int i = 1; i<=n; i++) {
            string temp = s.substr(index, i);
            if (st.find(temp) != st.end() && solve(s, index+i)) return t[index] = true;
        }
        return t[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t, -1, sizeof(t));
        for (string &word: wordDict) {
            st.insert(word);
        }

        return solve(s, 0);
    }
};
