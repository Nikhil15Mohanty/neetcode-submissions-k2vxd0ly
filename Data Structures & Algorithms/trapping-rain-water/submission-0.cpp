class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0;

        int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);

        int left_max_value = 0;
        // Traverse from left to right
        for (int i = 0; i < n; i++) {
            left_max_value = max(left_max_value, height[i]);
            left_max[i] = left_max_value;
        }

        int right_max_value = 0;
        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {
            right_max_value = max(right_max_value, height[i]);
            right_max[i] = right_max_value;
        }

        int answer = 0;
        // Calculate trapped water
        for (int i = 1; i < n - 1; i++) {
            answer += min(left_max[i], right_max[i]) - height[i];
        }

        return answer;
    }
};
