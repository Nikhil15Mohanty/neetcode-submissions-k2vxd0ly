class Solution {
public:
    int search(vector<int>& nums, int target) {
      // implemting binary search
      int size = nums.size();
      int l = 0;
      int r = size - 1;
      int ans = -1;
      while (l <= r) {
        int mid = (r + l ) / 2;
        if (target < nums[mid]) {
            r = mid - 1;
        } else if (target > nums[mid]) {
            l = mid + 1;
        }
         else {
            ans = mid;
            break;
         }
      }  

      return ans;
    }
};
