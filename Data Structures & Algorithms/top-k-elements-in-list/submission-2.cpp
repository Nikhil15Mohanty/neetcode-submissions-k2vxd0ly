class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int size = nums.size();
        unordered_map<int, int> mp;

        for (int num: nums) {
            mp[num]++;
        }

        vector<pair<int, int>> vp;
        for (auto& it: mp) {
            vp.push_back({ it.second, it.first});
        }

        sort(vp.rbegin(), vp.rend());

        vector<int> ans;
        for (int i = 0; i<k; i++) {
            ans.push_back(vp[i].second);
        }

        return ans;
    }
};
