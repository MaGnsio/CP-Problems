/**
 *    author:  MaGnsi0
 *    created: 13.08.2022 15:45:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int y;
    cin >> y;
    if (y % 4 == 0) {
        y += 2;
    } else if (y % 4 == 1) {
        y += 1;
    } else if (y % 4 == 3) {
        y += 3;
    }
    cout << y;
}
