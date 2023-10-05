/**
 *    author:  MaGnsi0
 *    created: 13.10.2021 16:27:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, c;
        cin >> a >> b >> c;
        int maxi = max({a, b, c});
        int x = (a == maxi && b != maxi && c != maxi ? 0 : maxi - a + 1);
        int y = (b == maxi && a != maxi && c != maxi ? 0 : maxi - b + 1);
        int z = (c == maxi && a != maxi && b != maxi ? 0 : maxi - c + 1);
        cout << x << " " << y << " " << z << "\n";
    }
}
