/**
 *    author:  MaGnsi0
 *    created: 10.01.2022 16:35:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        auto can = [](int x, int y) {
            while (x) {
                if (x == y) {
                    return true;
                }
                x /= 2;
            }
            return false;
        };
        vector<bool> visited(n, false);
        for (int i = n; i > 0; --i) {
            for (int j = 0; j < n; ++j) {
                if (visited[j]) {
                    continue;
                }
                if (can(a[j], i)) {
                    a[j] = i;
                    visited[j] =  true;
                    break;
                }
            }
        }
        sort(a.begin(), a.end());
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] != i + 1) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
}
