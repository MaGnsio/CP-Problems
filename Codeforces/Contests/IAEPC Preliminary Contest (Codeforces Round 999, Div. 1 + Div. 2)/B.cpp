/**
 *    author:  MaGnsi0
 *    created: 21.01.2025 19:41:01
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
        sort(a.begin(), a.end());
        int sides = -1;
        for (int i = n - 2; i >= 0; --i) {
            if (a[i] == a[i + 1]) {
                sides = a[i];
                a[i] = a[i + 1] = -1;
                break;
            }
        }
        if (sides == -1) {
            cout << -1 << "\n";
            continue;
        }
        sort(a.begin(), a.end());
        bool ok = false;
        for (int i = 3; i < n; ++i) {
            int seg = 2 * sides - (a[i] - a[i - 1]);
            if (seg > 0) {
                cout << sides << " " << sides << " " << a[i] << " " << a[i - 1] << "\n";
                ok = true;
                break;
            }
        }
        if (!ok) {
            cout << -1 << "\n";
        }
    }
}
