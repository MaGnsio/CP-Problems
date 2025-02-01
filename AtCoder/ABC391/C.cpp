/**
 *    author:  MaGnsi0
 *    created: 01.02.2025 16:10:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    int ans = 0;
    vector<int> pos(n), f(n, 1);
    iota(pos.begin(), pos.end(), 0);
    while (Q--) {
        int t; cin >> t;
        if (t == 2) {
            cout << ans << "\n";
            continue;
        }
        int p; cin >> p; p--;
        int j; cin >> j; j--;
        f[pos[p]]--; ans -= f[pos[p]] == 1;
        pos[p] = j; f[pos[p]]++; ans += f[pos[p]] == 2;
    }
}
