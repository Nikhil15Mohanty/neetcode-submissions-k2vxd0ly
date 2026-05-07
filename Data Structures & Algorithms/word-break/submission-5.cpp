#include<bits/stdc++.h>
class Solution {
public:
    bool solve(int start, string &s, unordered_set<string> &st, vector<int> &dp) {

        if (start == s.length()) return true;

        if (dp[start] != -1) return dp[start];

        for (int end = start; end < s.length(); end++) {

            string sub = s.substr(start, end - start + 1);

            if (st.count(sub)) {

                if (solve(end + 1, s, st, dp))
                    return dp[start] = true;
            }
        }

        return dp[start] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {

        unordered_set<string> st(wordDict.begin(), wordDict.end());

        vector<int> dp(s.length(), -1);

        return solve(0, s, st, dp);
    }
};
