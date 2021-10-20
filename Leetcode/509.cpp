/**
 *    author:  MaGnsi0
 *    created: 09/08/2021 21:24:50
**/

class Solution { //top down approach.
public:
    vector<int> f;
    Solution() {
        f = vector<int> (31, -1);
    }
    int fib(int n) {
        if (n <= 1) {
            return f[n] = n;
        }
        if (f[n] != -1) {
            return f[n];
        }
        return f[n] = fib(n - 1) + fib(n - 2);
    }
};

class Solution { //bottom up approach.
public:
    vector<int> f;
    Solution() {
        f = vector<int> (31, -1);
    }
    int fib(int n) {
        f[0] = 0, f[1] = 1;
        for (int i = 2; i <= n; ++i) {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};
