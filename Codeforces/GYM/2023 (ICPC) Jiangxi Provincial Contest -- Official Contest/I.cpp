/**
 *    author:  MaGnsi0
 *    created: 11.11.2023 00:38:04
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    vector<int> ans(n);
    for (int i = 0; i < n - 1; ++i) {
        int x; cin >> x; x--;
        int y; cin >> y; y--;
        int z; cin >> z;
        ans[x] ^= z;
        ans[y] ^= z;
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            int x; cin >> x; x--;
            int y; cin >> y; y--;
            int z; cin >> z;
            ans[x] ^= z;
            ans[y] ^= z;
        } else {
            int x; cin >> x; x--;
            cout << ans[x] << "\n";
        }
    }
}
