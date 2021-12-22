/**
 *    author:  MaGnsi0
 *    created: 26.10.2021 21:04:31
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long n;
    cin >> n;
    cout << (n > 2 ? (n & 1 ? n * (n - 1) * (n - 2) : (n % 3 == 0 ? (n - 1) * (n - 2) * (n - 3) : n * (n - 1) * (n - 3))) : n);
}
