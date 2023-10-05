/**
 *    author:  MaGnsi0
 *    created: 31.01.2023 21:37:08
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
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int64_t L = 0, R = 1e9;
        for (int i = 1; i < n; ++i) {
            if (a[i - 1] < a[i]) {
                R = min(R, (a[i] + a[i - 1]) / 2);
            } else if (a[i - 1] > a[i]) {
                L = max(L, (a[i] + a[i - 1] + 1) / 2);
            }
        }
        cout << (L <= R ? L : -1) << "\n";
    }
}
