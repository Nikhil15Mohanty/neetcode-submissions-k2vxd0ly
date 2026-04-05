class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result;
        if (k > n || k == 0) return result;
        int i = 0, j = 0;
        int max_value = INT_MIN;
        
        while (j < n) {
            max_value = max(max_value, nums[j]);
            
            if (j - i + 1 == k) {
                // Window size hit k, add max_value to result
                result.push_back(max_value);
                
                // If the element leaving window is max_value, recompute max_value
                if (nums[i] == max_value) {
                    max_value = INT_MIN;
                    for (int x = i + 1; x <= j; x++) {
                        max_value = max(max_value, nums[x]);
                    }
                }
                i++; // move window
            }
            j++;
        }
        return result;
    }
};
