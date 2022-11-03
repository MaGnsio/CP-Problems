/**
 *    author:  MaGnsi0
 *    created: 14.10.2022 19:32:13
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a[3];
        cin >> a[0] >> a[1] >> a[2];
        sort(a, a + 3);
        cout << (a[0] + a[1] == a[2] ? "YES" : "NO") << "\n";
    }
}
