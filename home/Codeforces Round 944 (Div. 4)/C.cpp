/**
 *    author:  MaGnsi0
 *    created: 15.05.2024 19:29:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int a; cin >> a;
        int b; cin >> b;
        int c; cin >> c;
        int d; cin >> d;
        if (a > b) { swap(a, b); }
        if ((a < c && c < b) ==  (a < d && d < b)) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
}
