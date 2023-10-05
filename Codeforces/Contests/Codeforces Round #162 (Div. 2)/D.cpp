/**
 *    author:  MaGnsi0
 *    created: 21/09/2021 00:02:47
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n), dp(n, 1), d(N, 0);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    for (int i = 0; i < n; ++i) {
        vector<int> div;
        for (int j = 1; j * j <= v[i]; ++j) {
            if (v[i] % j) {
                continue;
            }
            if (j != 1) {
                div.push_back(j);
            }
            if (v[i] != j * j) {
                div.push_back(v[i] / j);
            }
        }
        for (int j = 0; j < (int)div.size(); ++j) {
            dp[i] = max(dp[i], d[div[j]] + 1);
        }
        for (int j = 0; j < (int)div.size(); ++j) {
            d[div[j]] = dp[i];
        }
    }
    cout << *max_element(dp.begin(), dp.end());
}
