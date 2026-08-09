class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mp;
        int start_index = 0;
        int left = 0, right = 0;
        int minLength = INT_MAX;
        int countRequired = t.length();

        for (auto ch: t) {
            mp[ch]++;
        }


        for(; right < s.length(); right++) {
            char currentChar = s[right];
            if (mp[currentChar] > 0) {
                countRequired--;
            }
            mp[currentChar]--;

            while(countRequired == 0) {
                if (right - left + 1 < minLength) {
                    minLength = right-left+1;
                    start_index = left;
                }

                char current_left_char = s[left];
                mp[current_left_char]++;

                if (mp[current_left_char] > 0)
                    countRequired++;
                left++;
            }
        }

        return minLength == INT_MAX ? "": s.substr(start_index, minLength);


    }
};
