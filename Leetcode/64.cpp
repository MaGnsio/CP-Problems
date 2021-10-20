/**
 *    author:  MaGnsi0
 *    created: 09/08/2021 21:41:39
**/

class Solution { //top down approach
public:
    int dp(vector<vector<int>>& grid, vector<vector<int>>& v, int n, int m) {
        if (!n && !m) {
            return v[n][m] = grid[n][m];
        }
        if (v[n][m] != -1) {
            return v[n][m];
        }
        if (n && m) {
            return v[n][m] = grid[n][m] + min(dp(grid, v, n - 1, m), dp(grid, v, n, m - 1));
        } else if (n) {
            return v[n][m] = grid[n][m] + dp(grid, v, n - 1, m);
        } else {
            return v[n][m] = grid[n][m] + dp(grid, v, n, m - 1);
        }
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> v(n, vector<int>(m, -1));
        return dp(grid, v, n - 1, m -1);
    }
};

class Solution { //bottom up approach (backward)
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i && j) {
                    grid[i][j] = grid[i][j] + min(grid[i - 1][j], grid[i][j - 1]);
                } else if (i) {
                    grid[i][j] = grid[i][j] + grid[i - 1][j];
                } else if (j) {
                    grid[i][j] = grid[i][j] + grid[i][j - 1];
                }
            }
        }
        return grid[n - 1][m - 1];
    }
};

class Solution { //bottom up approach (forward)
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int dp[n][m][2];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i][j][0] = dp[i][j][1] = 1e6;
            }
        }
        dp[0][0][0] = dp[0][0][1] = grid[0][0];
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (i + 1 < n) {
                    if (dp[i][j][0] != 1e6 && dp[i][j][1] != 1e6) {
                        dp[i + 1][j][0] = min(dp[i][j][0], dp[i][j][1]) + grid[i + 1][j];
                    } else if (dp[i][j][0] != 1e6) {
                        dp[i + 1][j][0] = dp[i][j][0] + grid[i + 1][j];
                    } else if (dp[i][j][1] != 1e6) {
                        dp[i + 1][j][0] = dp[i][j][1] + grid[i + 1][j];
                    }
                }
                if (j + 1 < m) {
                    if (dp[i][j][0] != 1e6 && dp[i][j][1] != 1e6) {
                        dp[i][j + 1][1] = min(dp[i][j][0], dp[i][j][1]) + grid[i][j + 1];
                    } else if (dp[i][j][0] != 1e6) {
                        dp[i][j + 1][1] = dp[i][j][0] + grid[i][j + 1];
                    } else if (dp[i][j][1] != 1e6) {
                        dp[i][j + 1][1] = dp[i][j][1] + grid[i][j + 1];
                    }
                }
            }
        }
        return min(dp[n - 1][m - 1][0], dp[n - 1][m - 1][1]);
    }
};
