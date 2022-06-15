/**
 *    author:  MaGnsi0
 *    created: 02.06.2022 16:22:08
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> P(N, 1);
    for (int i = 1; i < N; ++i) {
        P[i] = 2 * P[i - 1];
        P[i] %= MOD;
    }
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        mp[x]++;
    }
    int ans = 0;
    for (auto& [x, y] : mp) {
        ans += P[y];
        ans -= 1;
        ans += MOD;
        ans %= MOD;
    }
    cout << ans;
}
