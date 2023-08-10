/**
 *    author:  MaGnsi0
 *    created: 07.07.2023 01:23:59
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, x;
        cin >> n >> x;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int y; cin >> y;
            if ((y & x) == x) { a.push_back(y); }
        }
        n = (int)a.size();
        if (n == 0) {
            cout << -1 << "\n";
            continue;
        }
        sort(a.begin(), a.end(), [](int x, int y) {
                return __builtin_popcount(x) > __builtin_popcount(y);
            });
        int ans = n;
        for (int i = 0; i < 27; ++i) {
            if ((x >> i) & 1) { continue; }
            int cnt = 0;
            for (int j = 0; j < n; ++j) {
                if (a[j] == -1) { continue; }
                if ((a[j] >> i) & 1) { cnt++; }
            }
            if (cnt == ans) {
                for (int j = 0; j < n; ++j) {
                    if (a[j] == -1) { continue; }
                    if ((a[j] >> i) & 1) {
                        a[j] = -1;
                        ans--;
                        break;
                    }
                }
            }
        }
        int val = (1 << 28) - 1;
        for (int i = 0; i < n; ++i) {
            if (a[i] != -1) {
                val = val & a[i];
            }
        }
        cout << (val == x ? ans : -1) << "\n";
    }
}
