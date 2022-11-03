/**
 *    author:  MaGnsi0
 *    created: 21.07.2022 16:34:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> b(n);
    for (int i = 1; i < n; ++i) {
        b[i] = max(int64_t(0), a[i - 1] - a[i]);
    }
    for (int i = 1; i < n; ++i) {
        b[i] += b[i - 1];
    }
    vector<int64_t> c(n);
    for (int i = n - 2; i >= 0; --i) {
        c[i] = max(int64_t(0), a[i + 1] - a[i]);
    }
    for (int i = n - 2; i >= 0; --i) {
        c[i] += c[i + 1];
    }
    for (int i = 0; i < q; ++i) {
        int s, t;
        cin >> s >> t;
        if (s < t) {
            cout << b[t - 1] - b[s - 1] << "\n";
        } else {
            cout << c[t - 1] - c[s - 1] << "\n";
        }
    }
}
