/**
 *    author:  MaGnsi0
 *    created: 14.11.2021 16:18:22
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string x, y;
    cin >> x >> y;
    for (auto& d : x) {
        if (d < '0' || d > '9') {
            cout << "NaN";
            return 0;
        }
    }
    for (auto& d : y) {
        if (d < '0' || d > '9') {
            cout << "NaN";
            return 0;
        }
    }
    cout << stoll(x) - stoll(y);
}
