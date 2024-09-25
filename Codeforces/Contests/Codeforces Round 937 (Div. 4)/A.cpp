/**
 *    author:  MaGnsi0
 *    created: 26.09.2024 00:34:17
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
        cout << (a < b && b < c ? "STAIR" : (a < b && b > c ? "PEAK" : "NONE")) << "\n";
    }
}
