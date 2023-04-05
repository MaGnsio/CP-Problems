/**
 *    author:  MaGnsi0
 *    created: 25.12.2022 06:09:21
**/

class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int64_t MOD = 1e9 + 7;
        int n = (int)nums.size();
        vector<int64_t> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            pre[i] = pre[i - 1] + nums[i];
        }
        vector<vector<vector<int64_t>>> dp(n, vector<vector<int64_t>>(k + 1, vector<int64_t>(2, -1)));
        function<int64_t(int, int, int)> solve = [&](int x, int y, int z) {
            if (x == n) {
                return int64_t(y == k && z == 1);
            }
            if (dp[x][y][z] != -1) {
                return dp[x][y][z];
            }
            dp[x][y][z] = 0;
            if (z == 0) {
                dp[x][y][z] = solve(x + 1, y, z);
                dp[x][y][z] %= MOD;
                if (y + nums[x] < k) {
                    dp[x][y][z] += solve(x + 1, y + nums[x], z);
                } else {
                    dp[x][y][z] += solve(x + 1, min(pre[x] - y - nums[x], int64_t(k)), 1);
                }
                dp[x][y][z] %= MOD;
            } else {
                dp[x][y][z] = solve(x + 1, y, z);
                dp[x][y][z] %= MOD;
                if (y + nums[x] < k) {
                    dp[x][y][z] += solve(x + 1, y + nums[x], z);
                } else {
                    dp[x][y][z] += solve(x + 1, k, z);
                }
                dp[x][y][z] %= MOD;
            }
            return dp[x][y][z];
        };
        return solve(0, 0, 0);
    }
};
