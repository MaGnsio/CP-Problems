/**
 *    author:  MaGnsi0
 *    created: 18/09/2021 13:55:10
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string a, b, c, s;
    cin >> a >> b >> c >> s;
    for (auto& x : s) {
        if (x == '1') {
            cout << a;
        } else if (x == '2') {
            cout << b;
        } else {
            cout << c;
        }
    }
}
