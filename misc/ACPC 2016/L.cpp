#include <bits/stdc++.h>

using namespace std;

const int64_t OO = 1e15;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, q;
        cin >> n >> q;
        vector<int64_t> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i] >> b[i];
        }
        int64_t L = -OO, R = OO; 
        for (int i = 0; i < n; ++i) {
            int64_t l = max(a[i], b[i]), r = l;
            for (int j = 0; j < n; ++j) {
                if (min(a[j], b[j]) >= l) {
                    r = max(r, min(a[j], b[j]));
                } else if (max(a[j], b[j]) >= l) {
                    r = max(r, max(a[j], b[j]));
                } else {
                    l = 0, r = -1;
                    break;
                }
            }
            if (l <= r) {
                L = max(L, l);
                R = min(R, r);
            }
            l = min(a[i], b[i]), r = l;
            for (int j = 0; j < n; ++j) {
                if (min(a[j], b[j]) >= l) {
                    r = max(r, min(a[j], b[j]));
                } else if (max(a[j], b[j]) >= l) {
                    r = max(r, max(a[j], b[j]));
                } else {
                    l = 0, r = -1;
                    break;
                }
            }
            if (l <= r) {
                L = max(L, l);
                R = min(R, r);
            }
        }
        for (int i = 0; i < q; ++i) {
            int64_t x;
            cin >> x;
            cout << (L <= x && x <= R ? "YES" : "NOT SURE");
            if (i < q - 1) { cout << "\n"; }
        }
        if (T) { cout << "\n"; }
    }
}
