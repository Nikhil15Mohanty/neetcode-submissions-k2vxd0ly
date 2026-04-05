#include<cstring>
class Solution {
public:

    int t[101];
    int solve(vector<int>& cost, int index, int size) {
        if (index >=size) {
            return 0;
        }

        if(t[index]!=-1) return t[index];

        int take_single_step = cost[index] + solve(cost, index + 1, size);
        int take_two_step = cost[index] + solve(cost, index + 2, size);

        return t[index] = min(take_single_step, take_two_step);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        memset(t, -1 , sizeof(t));
        int size = cost.size();

        if (size == 2) {
            return min(cost[0], cost[1]);
        }

        int result = min(solve(cost, 0, size), solve(cost,1, size));
        return result;
    }
};
