/**
 *    author:  MaGnsi0
 *    created: 09.11.2022 21:32:20
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int64_t ans = (a[0] + 1);
    for (int i = 1; i < (int)a.size(); ++i) {
        ans *= (a[i] - a[i - 1] + 1);
        ans %= MOD;
    }
    cout << ans;
}
