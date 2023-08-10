/**
 *    author:  MaGnsi0
 *    created: 17.04.2023 22:35:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T, F = 1;
    cin >> T;
    while (T--) {
        if (F) {
            F = 0;
        } else {
            cout << "\n";
        }
        int n;
        cin >> n;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool ok = true;
        for (int i = 1; i + 1 < n; ++i) {
            if (a[i - 1] == 0) { continue; }
            if (a[i] == 0) { continue; }
            if (a[i + 1] == 0) { continue; }
            if (a[i] > a[i - 1] && a[i] < a[i + 1]) {
                ok = false;
            }
            if (a[i] < a[i - 1] && a[i] > a[i + 1]) {
                ok = false;
            }
            if (a[i] == a[i - 1] || a[i] == a[i + 1]) {
                ok = false;
            }
        }
        if (ok == false) {
            cout << "NO";
            continue;
        }
        vector<int64_t> b = a;
        for (int i = 0; i < n; i += 2) {
            if (b[i] == 0) {
                b[i] = -1;
            }
        }
        for (int i = 1; i < n; i += 2) {
            if (b[i] == 0) {
                b[i] = 1e9 + 1;
            }
        }
        ok = true;
        for (int i = 1; i + 1 < n; ++i) {
            if ((b[i] > b[i - 1] && b[i] > b[i + 1]) || (b[i] < b[i - 1] && b[i] < b[i + 1])) {
                continue;
            }
            ok = false;
        }
        b = a;
        if (ok) {
            cout << "YES";
            continue;
        }
        for (int i = 0; i < n; i += 2) {
            if (b[i] == 0) {
                b[i] = 1e9 + 1;
            }
        }
        for (int i = 1; i < n; i += 2) {
            if (b[i] == 0) {
                b[i] = -1;
            }
        }
        ok = true;
        for (int i = 1; i + 1 < n; ++i) {
            if ((b[i] > b[i - 1] && b[i] > b[i + 1]) || (b[i] < b[i - 1] && b[i] < b[i + 1])) {
                continue;
            }
            ok = false;
        }
        cout << (ok ? "YES" : "NO");
    }
}
