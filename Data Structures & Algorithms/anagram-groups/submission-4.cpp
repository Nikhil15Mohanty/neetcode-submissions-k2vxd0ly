class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_map;
        for (auto &s: strs) {
            string keyValue = s;
            sort(keyValue.begin(), keyValue.end());
            hash_map[keyValue].push_back(s);
        }

        vector<vector<string>> result;
        for (auto &p: hash_map) {
            result.push_back(p.second);
        }

        return result;
    }
};
