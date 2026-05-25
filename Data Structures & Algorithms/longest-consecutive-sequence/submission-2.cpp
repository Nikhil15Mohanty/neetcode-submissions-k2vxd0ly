class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int longest = 0;
        for (int num: nums) {
            st.insert(num);
        }

        for (int num: st) {
            if (st.find(num-1) == st.end()) {
                int currentNum = num;
                int count = 1;

                while(st.find(currentNum+1) != st.end()) {
                    currentNum++;
                    count += 1;
                }

                longest = max(longest, count);
            }

        }
        return longest;
    }
};
