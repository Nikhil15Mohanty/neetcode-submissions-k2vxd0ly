class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        deque<int> d;
        vector<int> results;
        for (int i = 0; i < n; i++) {
            //step 1 remove the front element if size get out of window
            while (!d.empty() && d.front() <= i - k ) {
                d.pop_front();
            }
            //step 2 remove the back element if current element is greater than back
            while(!d.empty() && nums[i] > nums[d.back()]) {
                d.pop_back();
            }

            d.push_back(i);

            if (i >= k - 1){
                results.push_back(nums[d.front()]);
            }


        }
        return results;
    }
};
