/**
 *    author:  MaGnsi0
 *    created: 31.10.2021 22:34:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long x, y;
        cin >> x >> y;
        cout << (x > y ? x + y : y - (y % x) / 2) << "\n";
    }
}
