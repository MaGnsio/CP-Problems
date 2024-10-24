/**
 *    author:  MaGnsi0
 *    created: 24.10.2024 17:43:05
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int x = 0, turn = 0, i = 1;
        while (abs(x) <= n) {
            x += (turn ? 1 : -1) * (2 * i - 1);
            turn ^= 1; i++;
        }
        cout << (turn ? "Sakurako" : "Kosuke") << "\n";
    }
}
