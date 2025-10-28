/**
 *    author:  MaGnsi0
 *    created: 28.10.2025 17:33:35
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int a[4]; for (int& x : a) { cin >> x; }
        sort(a, a + 4);
        cout << (a[0] == a[3] ? "YES" : "NO") << "\n";
    }
}
