class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash_map;
        for(auto &num: nums) {
            if (hash_map.find(num) != hash_map.end()) {
                hash_map[num] = hash_map[num] + 1;
            } else {
                hash_map[num] = 1;
            }
        }

        for (const auto& pair: hash_map) {
            if (pair.second > nums.size() / 2) {
                return pair.first;
            }
        }
        return -1;
    }
};