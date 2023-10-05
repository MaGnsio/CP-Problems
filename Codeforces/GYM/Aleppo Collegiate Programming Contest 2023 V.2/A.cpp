/**
 *    author:  MaGnsi0
 *    created: 29.08.2023 16:14:16
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 100;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        int64_t y; cin >> y;
        a[i] = __gcd(1LL * x, y);
    }
    sort(a.begin(), a.end());
    if (x == 1) {
        cout << 1;
        return 0;
    }
    vector<int> b;
    for (int i = 1; 1LL * i * i <= x; ++i) {
        if (x % i == 0) {
            b.push_back(i);
            if (x != i * i) {
                b.push_back(x / i);
            }
        }
    }
    sort(b.begin(), b.end());
    int m = (int)b.size();
    map<int, int> C, J;
    for (int i = 0; i < n; ++i) {
        C[a[i]]++;
    }
    for (int i = 0; i < m; ++i) {
        J[b[i]] = i;
    }
    vector<int> c;
    for (int i = 1; i < m; ++i) {
        int k = min(C[b[i]], 30);
        for (int j = 0; j < k; ++j) {
            c.push_back(i);
        }
    }
    vector<vector<int>> I(m, vector<int>(m));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < m; ++j) {
            I[i][j] = J[__gcd(1LL * b[i] * b[j], 1LL * x)];
        }
    }
    vector<int> dp(m, OO); dp[0] = 0;
    for (auto i : c) {
        for (int j = m - 1; j >= 0; --j) {
            dp[I[i][j]] = min(dp[I[i][j]], dp[j] + 1);
        }
    }
    cout << (dp[m - 1] == OO ? -1 : dp[m - 1]);
}
