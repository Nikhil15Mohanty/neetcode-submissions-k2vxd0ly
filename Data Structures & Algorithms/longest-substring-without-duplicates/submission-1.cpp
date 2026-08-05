class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int size =  s.length();
        set<char> words;
        int left = 0;
        int count = 0;

        for (int right = 0; right<size; right++) {

            while(words.count(s[right])) {
                words.erase(s[left]);
                left++;
            }

            words.insert(s[right]);
            count = max(count, right - left + 1);
        }

        return count;
    }
};
