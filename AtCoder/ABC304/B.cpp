/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 15:05:03
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string zeros = "";
    while (n > 999) {
        n -= n % 10, n /= 10;
        zeros += "0";
    }
    cout << n << zeros;
}
