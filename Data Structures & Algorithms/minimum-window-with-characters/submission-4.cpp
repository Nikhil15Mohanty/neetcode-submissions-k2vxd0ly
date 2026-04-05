class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        int minWindowSize = INT_MAX;
        int start_i = 0;
        if (t.length() > n) {
            return "";
        }

        unordered_map<char,int> map;
        for (char &ch : t) {
            map[ch]++;
        }

        int i = 0, j = 0, requiredCount = t.length();
        while (j < n) {
            // check if character is present or not
            if (map[s[j]] > 0) {
                requiredCount--;
            }
            map[s[j]]--;


            while(requiredCount == 0) {
                // shrinking process start
                if (minWindowSize > j - i + 1) {
                    minWindowSize = j - i + 1;
                    start_i = i;
                }

                ++map[s[i]];
                if (map[s[i]] > 0) {
                    requiredCount++;
                }

                i++;

            }

            j++;

        }

        return minWindowSize == INT_MAX ? "" : s.substr(start_i, minWindowSize);
    }
};
