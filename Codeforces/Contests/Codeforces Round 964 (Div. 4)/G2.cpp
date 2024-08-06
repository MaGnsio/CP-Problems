/**
 *    author:  MaGnsi0
 *    created: 06.08.2024 18:25:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int, int)> ask = [&](int x, int y) {
        cout << "? " << x << " " << y << endl;
        int res; cin >> res; return res;
    };
    function<int(int, int)> solve = [&](int l, int r) {
        if (l == r) { return l; }
        if (l + 1 == r) {
            int res = ask(l, r);
            return (res == l * (r + 1) ? r : l);
        }
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        int res = ask(m1, m2);
        if (res == m1 * m2) {
            return solve(m2 + 1, r);
        }
        if (res == m1 * (m2 + 1)) {
            return solve(m1 + 1, m2);
        }
        return solve(l, m1);
    };
    int T; cin >> T;
    while (T--) {
        int x = solve(2, 999);
        cout << "! " << x << endl;
    }
}
