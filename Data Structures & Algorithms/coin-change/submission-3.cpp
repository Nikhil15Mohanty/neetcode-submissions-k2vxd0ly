#include <cstring>
class Solution {
public:
    int t[11][10001];

    int solve(int i, int amount, vector<int>& coins) {
        if (amount == 0) return 0;
        if (i >= coins.size()) return 1e9;
        if (amount < 0) return 1e9;

        if (t[i][amount] != -1) return t[i][amount];

        int notTake = solve(i + 1, amount, coins);

        int take = 1e9;
        int res = solve(i, amount - coins[i], coins);
        if (res != 1e9) {
            take = 1 + res;
        }

        return t[i][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        memset(t, -1, sizeof(t));
        int ans = solve(0, amount, coins);
        return ans >= 1e9 ? -1 : ans;
    }
};