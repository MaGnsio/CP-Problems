/**
 *    author:  MaGnsi0
 *    created: 20.11.2025 17:37:59
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
            cin >> a[i]; a[i]--;
        }
        vector<int> b(n);
        for (int i = 0; i < n; ++i) {
            b[a[i]] = i;
        }
        vector<int> c(n);
        for (int i = n - 1; i >= 0; --i) {
            c[i] = i == n - 1 ? i : (a[c[i + 1]] > a[i] ? c[i + 1] : i);
        }
        int l = n;
        vector<pair<int, int>> edges;
        for (int i = 0; i < n; ++i) {
            if (b[i] >= l) { continue; }
            int s = b[i] + 1, e = l - 1, x = (l == n ? -1 : c[l]);
            if (x != -1 && a[x] < i) { break; }
            for (int j = s; j <= e; ++j) {
                edges.emplace_back(i + 1, a[j] + 1);
            }
            if (x != -1) {
                edges.emplace_back(i + 1, a[x] + 1);
            }
            l = b[i];
        }
        cout << (l == 0 ? "YES" : "NO") << "\n";
        if (l == 0) {
            for (auto [u, v] : edges) {
                cout << u << " " << v << "\n";
            }
        }
    }
}
