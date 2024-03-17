/**
 *    author:  MaGnsi0
 *    created: 05.01.2024 21:20:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int Q; cin >> Q;
    while (Q--) {
        int year; cin >> year; year--;
        cout << a[year % n] << b[year % m] << "\n";
    }
}
