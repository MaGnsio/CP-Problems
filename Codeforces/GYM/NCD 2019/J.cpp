/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 22:05:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m), b(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        vector<int> c(n + 2, 0);
        for (int i = 0; i < m; ++i) {
            if (b[i] >= 0) {
                if (a[i] + b[i] > n) {
                    c[a[i]]++, c[n + 1]--;
                    c[1]++, c[a[i] + b[i] - n + 1]--;
                } else {
                    c[a[i]]++, c[a[i] + b[i] + 1]--;
                }
            } else {
                if (a[i] + b[i] <= 0) {
                    c[1]++, c[a[i] + 1]--;
                    c[n + a[i] + b[i]]++, c[n + 1]--;
                } else {
                    c[a[i] + b[i]]++, c[a[i] + 1]--;
                }
            }
        }
        for (int i = 1; i <= n + 1; ++i) {
            c[i] += c[i - 1];
        }
        int ans = 1;
        for (int i = 1; i <= n; ++i) {
            if (c[ans] < c[i]) { ans = i; }
        }
        cout << ans << " " << c[ans] << "\n";
    }
}
