/**
 *    author:  MaGnsi0
 *    created: 05.02.2023 14:37:20
**/
#include <bits/stdc++.h>

using namespace std;

const int OO = 2e9;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, w, h;
        cin >> n >> w >> h;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        if (w < h) {
            cout << "NO\n";
            continue;
        }
        bool ok = true;
        int L = -OO, R = OO;
        for (int i = 0; i < n; ++i) {
            int l = (a[i] - w) - (b[i] - h);
            int r = (a[i] + w) - (b[i] + h);
            if (l > R || L > r) {
                ok = false;
                break;
            }
            L = max(L, l);
            R = min(R, r);
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
