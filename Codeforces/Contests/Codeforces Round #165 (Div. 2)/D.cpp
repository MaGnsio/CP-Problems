/**
 *    author:  MaGnsi0
 *    created: 20/09/2021 20:20:51
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < n; ++i) {
        cin >> v[i];
        double x; cin >> x;
    }
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (v[i] <= v[j]) {
                dp[j] = max(dp[j], dp[i] + 1);
            }
        }
    }
    cout << n - *max_element(dp.begin(), dp.end());
}
