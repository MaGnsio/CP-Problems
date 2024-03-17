/**
 *    author:  MaGnsi0
 *    created: 06.01.2024 22:46:52
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
        vector<int> L(n, -1), R(n, n), I(n);
        for (int i = 0; i < n; ++i) {
            L[i] = i - 1;
            R[i] = i + 1;
        }
        iota(I.begin(), I.end(), 0);
        sort(I.begin(), I.end(), [&](int i, int j) {
                return a[i] > a[j];
            });
        if (a[I[n - 1]] != 0 || a[I[n - 2]] == 0) {
            cout << "NO\n";
            continue;
        }
        bool good = true;
        for (int i : I) {
            int x = -1;
            if (L[i] != -1) { x = max(x, a[L[i]]); }
            if (R[i] != n) { x = max(x, a[R[i]]); }
            if (a[i] > x + 1) {
                good = false;
                break;
            }
            if (L[i] != -1) { R[L[i]] = R[i]; }
            if (R[i] != n) { L[R[i]] = L[i]; }
        }
        cout << (good ? "YES" : "NO") << "\n";
    }
}
