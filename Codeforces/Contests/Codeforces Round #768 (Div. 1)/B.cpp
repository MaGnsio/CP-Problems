/**
 *    author:  MaGnsi0
 *    created: 02.02.2022 22:54:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), f(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            f[a[i]]++;
        }
        for (int i = 1; i <= n; ++i) {
            f[i] += f[i - 1];
        }
        int x = 1, y = n;
        for (int i = 1; i <= n; ++i) {
            int l = i, r = n;
            while (l <= r) {
                int m = (l + r) / 2;
                int in = f[m] - f[i - 1];
                int out = n - in;
                if (in - (out + 1) >= k - 1) {
                    if (y - x > m - i) {
                        x = i, y = m;
                    }
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
        }
        cout << x << " " << y << "\n";
        for (int i = 0; i < n; ++i) {
            if (a[i] >= x && a[i] <= y) {
                a[i] = 1;
            } else {
                a[i] = -1;
            }
        }
        for (int i = 1; i < n; ++i) {
            a[i] += a[i - 1];
        }
        int last = -1;
        for (int i = 0; i < n; ++i) {
            int B = a[i] - (last == -1 ? 0 : a[last]);
            if (B > 0) {
                if (k == 1) {
                    cout << last + 2 << " " << n << "\n";
                    break;
                } else {
                    cout << last + 2 << " " << i + 1 << "\n";
                    last = i;
                    k--;
                }
            }
        }
    }
}
