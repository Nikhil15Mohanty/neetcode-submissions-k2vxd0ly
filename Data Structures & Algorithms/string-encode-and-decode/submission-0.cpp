class Solution {
public:

    string encode(vector<string>& strs) {
        string s = "";
        for (auto str: strs) {
            s += to_string(str.length()) + "#" + str;
        }

        return s;
    }

    vector<string> decode(string s) {
        vector<string> strs;
        int i = 0; 
        while (i < s.length()) {
            int j = i;

            while(s[j] != '#') {
                j++;
            }

            int length = stoi(s.substr(i, j - i));
            string word = s.substr(j+1, length);
            strs.push_back(word);
            i = j+1+length;
        }

        return strs;
    }
};
