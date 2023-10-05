/**
 *    author:  MaGnsi0
 *    created: 14.12.2021 22:01:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a[7];
        for (int i = 0; i < 7; ++i) {
            cin >> a[i];
        }
        sort(a, a + 7);
        cout << a[0] << " " << a[1] << " " << (a[0] + a[1] == a[2] ? a[3] : a[2]) << "\n";
    }
}
