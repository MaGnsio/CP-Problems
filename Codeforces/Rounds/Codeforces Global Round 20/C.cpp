/**
 *    author:  MaGnsi0
 *    created: 23.04.2022 15:57:37
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
        int l = n, r = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] == a[i + 1]) {
                l = i + 1;
            }
        }
        for (int i = 0; i + 1 < n; ++i) {
            if (a[i] == a[i + 1]) {
                r = i;
            }
        }
        cout << (r == l ? 1 : max(r - l, 0)) << "\n";
    }
}
