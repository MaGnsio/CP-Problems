/**
 *    author:  MaGnsi0
 *    created: 04.05.2023 18:22:01
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
        vector<int> b = a;
        sort(b.begin(), b.end());
        int mex = 0;
        for (int i = 0; i < n; ++i) {
            mex += b[i] == mex;
        }
        int l = n, r = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == mex + 1) {
                l = min(l, i);
                r = max(l, i);
            }
        }
        if (l == n) {
            bool ok = false;
            for (int i = 0; i < n; ++i) {
                if (b[i] > mex) {
                    ok = true;
                }
                if (i && b[i] == b[i - 1]) {
                    ok = true;
                }
            }
            cout << (ok ? "YES" : "NO") << "\n";
        } else {
            for (int i = l; i <= r; ++i) {
                a[i] = mex;
            }
            b = a;
            sort(b.begin(), b.end());
            int mex2 = 0;
            for (int i = 0; i < n; ++i) {
                mex2 += b[i] == mex2;
            }
            cout << (mex + 1 == mex2 ? "YES" : "NO") << "\n";
        }
    }
}
