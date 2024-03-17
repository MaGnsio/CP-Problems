/**
 *    author:  MaGnsi0
 *    created: 28.12.2023 18:12:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int a[3];
        for (int& x : a) { cin >> x; }
        sort(a, a + 3);
        cout << (a[0] == a[1] ? a[2] : a[0]) << "\n";
    }
}
