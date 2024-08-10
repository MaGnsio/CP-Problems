/**
 *    author:  MaGnsi0
 *    created: 10.08.2024 15:04:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    reverse(a.begin(), a.end());
    int m = 0;
    for (int i = 0; i < n; ++i) {
        m = max(m, (int)a[i].size());
    }
    vector<string> b(m, "");
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            if (i < (int)a[j].size()) {
                b[i] += a[j][i];
            } else {
                b[i] += "*";
            }
        }
    }
    for (int i = 0; i < m; ++i) {
        while (b[i].back() == '*') {
            b[i].pop_back();
        }
        cout << b[i] << "\n";
    }
}
