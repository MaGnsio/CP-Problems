/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 15:16:45
**/
#include <bits/stdc++.h>

using namespace std;

const int D = 3;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    array<int, D> n;
    cin >> n[0]; n[1] = n[2] = n[0];
    map<array<int, D>, int> a;
    for (int i1 = 1; i1 <= n[0]; ++i1) {
        for (int i2 = 1; i2 <= n[1]; ++i2) {
            for (int i3 = 1; i3 <= n[2]; ++i3) {
                cin >> a[{i1, i2, i3}];
            }
        }
    }
    for (int k = 0; k < D; ++k) {
        for (int i1 = 1; i1 <= n[0]; ++i1) {
            for (int i2 = 1; i2 <= n[1]; ++i2) {
                for (int i3 = 1; i3 <= n[2]; ++i3) {
                    a[{i1, i2, i3}] += a[{i1 - (k == 0), i2 - (k == 1), i3 - (k == 2)}];
                }
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        array<int, D> L = {1, 1, 1};
        array<int, D> R = {1, 1, 1};
        for (int i = 0; i < D; ++i) {
            cin >> L[i] >> R[i];
        }
        int ans = 0;
        for (int i = 0; i < (1 << D); ++i) {
            array<int, D> k;
            for (int j = 0; j < D; ++j) {
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
