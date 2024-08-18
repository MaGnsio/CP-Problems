/**
 *    author:  MaGnsi0
 *    created: 19.08.2024 01:13:40
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    set<int> include;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x; x--;
        int y; cin >> y; y--;
        include.insert((x + y) % n);
    }
    for (int i = 0; i < n; ++i) {
        if ((int)include.size() == m) { break; }
        include.insert(i);
    }
    cout << n * m << "\n";
    for (int x : include) {
        for (int i = 0, j = x; i < n; ++i, --j) {
            cout << i + 1 << " " << ((j + n) % n) + 1 << "\n";
        }
    }
}
