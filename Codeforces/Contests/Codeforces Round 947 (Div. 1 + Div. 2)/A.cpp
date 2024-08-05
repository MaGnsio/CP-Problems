/**
 *    author:  MaGnsi0
 *    created: 28.05.2024 22:20:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            vector<int> b;
            for (int j = i; j < n; ++j) {
                b.push_back(a[j]);
            }
            for (int j = 0; j < i; ++j) {
                b.push_back(a[j]);
            }
            ok |= is_sorted(b.begin(), b.end());
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
}
