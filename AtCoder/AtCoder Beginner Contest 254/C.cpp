/**
 *    author:  MaGnsi0
 *    created: 09.06.2022 21:18:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<vector<int>> b(k);
    for (int i = 0; i < n; ++i) {
        b[i % k].push_back(a[i]);
    }
    for (int i = 0; i < k; ++i) {
        sort(b[i].begin(), b[i].end());
    }
    for (int i = 0; i < k; ++i) {
        for (int j = 0; j < (int)b[i].size(); ++j) {
            a[i + j * k] = b[i][j];
        }
    }
    bool ok = true;
    for (int i = 1; i < n; ++i) {
        ok &= bool(a[i] >= a[i - 1]);
    }
    cout << (ok ? "Yes" : "No");
}
