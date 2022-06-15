/**
 *    author:  MaGnsi0
 *    created: 29.05.2022 22:59:12
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int d;
    cin >> d;
    array<int, 5> n = {1, 1, 1, 1, 1};
    for (int i = 0; i < d; ++i) {
        cin >> n[i];
    }
    map<array<int, 5>, int> a;
    for (int i1 = 1; i1 <= n[0]; ++i1) {
        for (int i2 = 1; i2 <= n[1]; ++i2) {
            for (int i3 = 1; i3 <= n[2]; ++i3) {
                for (int i4 = 1; i4 <= n[3]; ++i4) {
                    for (int i5 = 1; i5 <= n[4]; ++i5) {
                        cin >> a[{i1, i2, i3, i4, i5}];
                    }
                }
            }
        }
    }
    for (int k = 0; k < 5; ++k) {
        for (int i1 = 1; i1 <= n[0]; ++i1) {
            for (int i2 = 1; i2 <= n[1]; ++i2) {
                for (int i3 = 1; i3 <= n[2]; ++i3) {
                    for (int i4 = 1; i4 <= n[3]; ++i4) {
                        for (int i5 = 1; i5 <= n[4]; ++i5) {
                            a[{i1, i2, i3, i4, i5}] += a[{i1 - (k == 0), i2 - (k == 1), i3 - (k == 2), i4 - (k == 3), i5 - (k == 4)}];
                        }
                    }
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        array<int, 5> L = {1, 1, 1, 1, 1};
        array<int, 5> R = {1, 1, 1, 1, 1};
        for (int i = 0; i < d; ++i) {
            cin >> L[i];
        }
        for (int i = 0; i < d; ++i) {
            cin >> R[i];
        }
        int ans = 0;
        for (int i = 0; i < (1 << 5); ++i) {
            array<int, 5> k;
            for (int j = 0; j < 5; ++j) {
                if ((i >> j) & 1) {
                    k[j] = R[j];
                } else {
                    k[j] = L[j] - 1;
                }
            }
            ans += (__builtin_popcount(i) & 1 ? 1 : -1) * a[k];
        }
        cout << ans << "\n";
    }
}
