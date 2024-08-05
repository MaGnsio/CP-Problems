/**
 *    author:  MaGnsi0
 *    created: 29.05.2024 23:11:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        for (int cliques = 1; cliques <= n; ++cliques) {
            bool good = true;
            int block = (n / cliques), r = (n % cliques);
            vector<int> a(n), c(n);
            for (int i = 0, y = 0; i < n; y++) {
                int j = i, count = 0;
                while (j < n && count < block + (y < r)) {
                    c[j] = y + 1;
                    j++, count++;
                }
                i = j;
            }
            for (int i = 0, x = 1; i < n; /*_*/) {
                int j = i;
                while (j < n && c[i] == c[j]) { j++; }
                int m = j - i;
                vector<int> b(m);
                iota(b.begin(), b.end(), x);
                int mid = m / 2;
                reverse(b.begin(), b.begin() + mid);
                reverse(b.begin() + mid, b.end());
                for (int k1 = i; k1 < j; ++k1) {
                    a[k1] = b[k1 - i];
                }
                for (int k1 = i; k1 < j; ++k1) {
                    for (int k2 = i + 1; k2 < j; ++k2) {
                        good = good && ((k2 - k1) + abs(a[k2] - a[k1]) <= k);
                    }
                }
                x = *max_element(b.begin(), b.end()) + 1, i = j;
            }
            if (good) {
                for (int i = 0; i < n; ++i) {
                    cout << a[i] << " ";
                }
                cout << "\n" << cliques << "\n";
                for (int i = 0; i < n; ++i) {
                    cout << c[i] << " ";
                }
                cout << "\n";
                break;
            }
        }
    }
}
