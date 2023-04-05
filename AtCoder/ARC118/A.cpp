/**
 *    author:  MaGnsi0
 *    created: 09.11.2022 21:56:58
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t t, n;
    cin >> t >> n;
    int64_t x = (n * 100 + t - 1) / t;
    cout << (100 + t) * x / 100 - 1;
}
