/**
 *    author:  MaGnsi0
 *    created: 20.10.2023 17:52:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int m; cin >> m;
        vector<int> g(m);
        for (int i = 0; i < m; ++i) {
            cin >> g[i];
        }
        int n; cin >> n;
        vector<int> h(n);
        for (int i = 0; i < n; ++i) {
            cin >> h[i];
        }
        assert(n >= m);
        int k = n - m + 1;
        vector<int> f(k);
        for (int i = 0; i < k; ++i) {
            int sum = h[i];
            for (int j = 0; j < i; ++j) {
                if (i - j >= m) { continue; }
                sum -= f[j] * g[i - j];
            }
            f[i] = sum / g[0];
        }
        cout << k << "\n";
        for (int i = 0; i < k; ++i) {
            cout << f[i] << " ";
        }
        cout << "\n";
    }
}
