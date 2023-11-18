/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 21:35:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int x; cin >> x;
        int y; cin >> y;
        cout << (x == y ? "Iskandar" : (x < y ? "Hamada" : "Bashar")) << "\n";
    }
}
