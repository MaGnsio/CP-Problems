/**
 *    author:  MaGnsi0
 *    created: 19.03.2026 05:42:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        map<int, int> f;
        for (int i = 0; i < n * n; ++i) {
            int x; cin >> x; f[x]++;
        }
        int maxf = 0;
        for (auto [_, x] : f) {
            maxf = max(maxf, x);
        }
        cout << (maxf <= n * (n - 1) ? "YES" : "NO") << "\n";
    }
}
