#include<bits/stdc++.h>
class Solution {
public: 
    int m,n;
    int t[101][101];
    int solve(vector<vector<int>>& obstacleGrid, int m, int n, int i, int j) {


        if (i < 0 || i >=m || j < 0 || j>=n || obstacleGrid[i][j] == 1) return 0;
        if (i == m -1 && j == n-1) return 1;
        if (t[i][j] != -1) return t[i][j];

        int down = solve(obstacleGrid, m, n, i + 1, j);
        int right = solve (obstacleGrid, m, n, i, j+1);

        return t[i][j] = down + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memset(t, -1, sizeof(t));
        int i = 0, j = 0;
        return solve (obstacleGrid, m,n,i,j);
    }
};