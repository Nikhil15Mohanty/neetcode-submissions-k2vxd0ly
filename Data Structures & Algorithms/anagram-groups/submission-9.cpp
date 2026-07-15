class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
     unordered_map<string, vector<string>> m;
     for (auto str: strs) {
        string key = str;
        sort(key.begin(), key.end());
        m[key].push_back(str);
     }

     vector<vector<string>> ans;
     for (auto &it: m) {
        ans.push_back(it.second);
     }

     return ans;
    }
};
