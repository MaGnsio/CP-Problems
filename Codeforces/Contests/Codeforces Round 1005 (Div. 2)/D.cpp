/**
 *    author:  MaGnsi0
 *    created: 16.02.2025 17:00:57
**/
#include <bits/stdc++.h>

using namespace std;

const int B = 30;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        reverse(a.begin(), a.end());
        vector<int> p(n);
        for (int i = 0; i < n; ++i) {
            p[i] = (i ? p[i - 1] : 0) ^ a[i];
        }
        vector<map<int, int>> pos(B);
        for (int i = n - 2; i >= 0; --i) {
            int val = 0;
            for (int bit = B - 1; bit >= 0; --bit) {
                if ((p[i] >> bit & 1) && (a[i + 1] >> bit & 1)) {
                    pos[bit][val | (1 << bit)] = i + 1;
                } else if (!(p[i] >> bit & 1) && (a[i + 1] >> bit & 1)) {
                    pos[bit][val] = i + 1;
                    val |= (1 << bit);
                } else if ((p[i] >> bit & 1) && !(a[i + 1] >> bit & 1)) {
                    val |= (1 << bit);
                }
            }
        }
        while (Q--) {
            int x; cin >> x;
            if (x < a[0]) {
                cout << 0 << (Q ? " " : "\n");
                continue;
            }
            int ans = n, val = 0;
            for (int bit = B - 1; bit >= 0; --bit) {
                if (x >> bit & 1) {
                    val |= (1 << bit);
                }
                if (pos[bit].count(val)) {
                    ans = min(ans, pos[bit][val]);
                }
            }
            cout << ans << (Q ? " " : "\n");
        }
    }
}
