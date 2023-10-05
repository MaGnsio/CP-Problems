/**
 *    author:  MaGnsi0
 *    created: 25.09.2023 17:39:55
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<vector<int>> a(n);
        for (int i = 0; i < n; ++i) {
            int m; cin >> m;
            a[i].resize(m);
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }
        vector<int> F(N);
        for (int i = 0; i < n; ++i) {
            for (int x : a[i]) {
                F[x]++;
            }
        }
        int ans = 0;
        for (int i = 0; i < N; ++i) {
            if (F[i] == 0) { continue; }
            int val = 0;
            vector<int> f(N);
            for (int j = 0; j < n; ++j) {
                bool take = true;
                for (int x : a[j]) {
                    if (x == i) {
                        take = false;
                        break;
                    }
                }
                if (take) {
                    for (int x : a[j]) {
                        val += f[x] == 0;
                        f[x]++;
                    }
                }
            }
            ans = max(ans, val);
        }
        cout << ans << "\n";
    }
}
