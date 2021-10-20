/**
 *    author:  MaGnsi0
 *    created: 09/08/2021 21:32:45
**/

class Solution { //top down approach
public:
    vector<int> dp;
    Solution() {
        dp = vector<int>(46, -1);
    }
    int climbStairs(int n) {
        if (n <= 1) {
            return dp[n] = 1;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        return dp[n] = climbStairs(n - 1) + climbStairs(n - 2);
    }
};

class Solution { //bottom up approach
public:
    vector<int> dp;
    Solution() {
        dp = vector<int>(46, -1);
    }
    int climbStairs(int n) {
        dp[0] = dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
