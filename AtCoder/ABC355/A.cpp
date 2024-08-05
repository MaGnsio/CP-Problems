/**
 *    author:  MaGnsi0
 *    created: 25.05.2024 15:00:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int x; cin >> x;
    int y; cin >> y;
    cout << (x == y ? -1 : (x == 1 || y == 1 ? (x == 2 || y == 2 ? 3 : 2) : 1));
}
