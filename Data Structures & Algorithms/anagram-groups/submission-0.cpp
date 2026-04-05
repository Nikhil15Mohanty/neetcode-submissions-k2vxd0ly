class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        vector<bool> used(strs.size(), false);
        for (int i = 0; i < strs.size(); i++) {
            if (used[i]) {
                continue;
            }
            vector<string> group;
            group.push_back(strs[i]);
            used[i] = true;
            string i_string = strs[i];
            sort(i_string.begin(), i_string.end());
            for (int j = i + 1; j < strs.size(); j++) {
                string currentStr = strs[j];
                sort(currentStr.begin(), currentStr.end());
                if (!used[j] && currentStr == i_string) {
                    used[j] = true;
                    group.push_back(strs[j]);
                }
            }
            result.push_back(group);
        }
        return result;
    }
};
