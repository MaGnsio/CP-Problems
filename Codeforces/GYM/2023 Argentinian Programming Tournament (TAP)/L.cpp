/**
 *    author:  MaGnsi0
 *    created: 21.09.2023 10:48:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = a + c, y = b + d;
    cout << (x == y ? "D" : (x < y ? "P" : "A"));
}
