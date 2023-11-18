/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 22:18:24
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
    vector<int64_t> b;
    for (int i = 1; i < n; ++i) {
        b.push_back(a[i - 1] - a[i]);
    }
    sort(b.rbegin(), b.rend());
    for (int i = 1; i < n - 1; ++i) {
        b[i] += b[i - 1];
    }
    int Q; cin >> Q;
    while (Q--) {
        int t; cin >> t;
        if (t == 0) { //lol
            int x; cin >> x;
        } else {
            int k; cin >> k;
            cout << a[0] - (k == 1 ? 0 : b[k - 2]) - a[n - 1] << "\n";
        }
    }
}
