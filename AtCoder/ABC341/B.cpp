/**
 *    author:  MaGnsi0
 *    created: 17.02.2024 14:02:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int64_t> b(n), c(n);
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i] >> c[i];
    }
    for (int i = 0; i + 1 < n; ++i) {
        int64_t x = a[i] / b[i];
        a[i + 1] += x * c[i];
    }
    cout << a[n - 1];
}
