/**
 *    author:  MaGnsi0
 *    created: 23.08.2022 13:25:10
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

template <typename T>
T power(T b, T p, T m) {
    T res = 1;
    while (p) {
        if (p & 1) {
            res = ((res % m) * (b % m)) % m;
        }
        b = ((b % m) * (b % m)) % m;
        p >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x, y;
    cin >> x >> y;
    if (y % x) {
        cout << 0;
        return 0;
    }
    vector<int> divs;
    for (int i = 1; i * i <= y; ++i) {
        if (y % i == 0) {
            divs.push_back(i);
            if (y != i * i) {
                divs.push_back(y / i);
            }
        }
    }
    sort(divs.begin(), divs.end());
    map<int, int64_t> dp;
    dp[y] = 1;
    for (int i = (int)divs.size() - 2; i >= 0; --i) {
        dp[divs[i]] = power<int64_t>(2, y / divs[i] - 1, MOD);
        for (int j = i + 1; j < (int)divs.size(); ++j) {
            if (divs[j] % divs[i] == 0) {
                dp[divs[i]] -= dp[divs[j]];
                dp[divs[i]] += MOD;
                dp[divs[i]] %= MOD;
            }
        }
    }
    cout << dp[x];
}
