/**
 *    author:  MaGnsi0
 *    created: 30.03.2022 21:12:06
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    if(a > b + c) {
        cout << "YES\n";
        cout << (a == 1 ? 0 : 2 * (b + c) + 1);
    } else {
        cout << "NO";
    }
}
