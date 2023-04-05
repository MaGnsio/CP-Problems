/**
 *    author:  MaGnsi0
 *    created: 04.02.2023 09:25:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    bool ok = false;
    for (int mask = 0; mask < (1 << n); ++mask) {
        int64_t sum = 0;
        for (int j = 0; j < n; ++j) {
            sum += ((mask >> j) & 1 ? 1 : -1) * a[j];
        }
        ok |= sum % x == 0;
    }
    cout << (ok ? "YES" : "NO");
}
