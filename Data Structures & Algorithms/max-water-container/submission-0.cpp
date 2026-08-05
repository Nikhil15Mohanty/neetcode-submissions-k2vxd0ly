class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int leftBuilding = 0;
        int rightBuilding = n - 1;

        int maxArea = -1;

        while(leftBuilding < rightBuilding) {
            int width = rightBuilding - leftBuilding;
            int area = min(heights[leftBuilding], heights[rightBuilding]) * width;
            maxArea = max(area, maxArea);

            if (heights[leftBuilding] < heights[rightBuilding]) {
                leftBuilding++;
            } else {
                rightBuilding--;
            }
        }
        return maxArea;

    }
};
