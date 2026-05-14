#include<bits/stdc++.h>
class Solution {
public:
    int t[201][201];
    int m,n;
    int solve(vector<vector<int>>& grid, int i, int j) {
        if (i == m-1 && j == n-1) return grid[i][j];

        if (t[i][j] != -1) return t[i][j];

        if (i < 0 || i >= m || j < 0 || j >= n) {
            return INT_MAX;
        }

        int right = solve(grid, i, j+1);
        int down = solve(grid, i+1, j);

        return t[i][j] = grid[i][j] + min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
        memset(t, -1, sizeof(t));
        m = grid.size();
        n = grid[0].size();

        return solve(grid,0,0);
    }
};