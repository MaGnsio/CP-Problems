/**
 *    author:  MaGnsi0
 *    created: 10.11.2023 16:48:26
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> a(n);
        for (int i = 0; i < m; ++i) {
            int x; cin >> x; x--;
            int y; cin >> y; y--;
            a[x]++, a[y]++;
        }
        sort(a.rbegin(), a.rend());
        while (a.back() == 1) { a.pop_back(); }
        int X = a[0], Y = a.back() - 1;
        if (a[0] == a[1]) {
            X = a.back(), Y = a[0] - 1;
        }
        cout << X << " " << Y << "\n";
    }
}
