/**
 *    author:  MaGnsi0
 *    created: 25.02.2023 15:37:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    double n, x;
    cin >> n >> x;
    double a = x * log(n);
    double b = 0;
    for (int i = 1; i <= x; ++i) {
        b += log(i);
    }
    cout << (isgreater(a, b) ? "zozo" : "zezo");
}
