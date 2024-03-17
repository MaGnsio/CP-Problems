/**
 *    author:  MaGnsi0
 *    created: 16.01.2024 16:39:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n, f, x, y;
        cin >> n >> f >> x >> y;
        vector<int64_t> a(n + 1); 
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        int64_t need = 0;
        for (int i = 1; i <= n; ++i) {
            need += min(x * (a[i] - a[i - 1]), y);
        }
        cout << (need < f ? "YES" : "NO") << "\n";
    }
}
