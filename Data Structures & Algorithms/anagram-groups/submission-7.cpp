class Solution {
public:
    string getFrequencyCount(string str) {
        int arr[26] = {0};
        string result = "";
        for (char ch: str) {
            arr[ch - 'a'] += 1;
        }

        for (int i = 0; i< 26; i++) {
            if (arr[i] > 0) {
                result += (char)('a' + i);
                result += to_string(arr[i]);
            }
        }

        return result;

    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash_map;
        for (string str: strs) {
            string frequency = getFrequencyCount(str);
            hash_map[frequency].push_back(str);
        }

        vector<vector<string>> result;
        for (auto& it: hash_map) {
            result.push_back(it.second);
        }

        return result;
    }
};
