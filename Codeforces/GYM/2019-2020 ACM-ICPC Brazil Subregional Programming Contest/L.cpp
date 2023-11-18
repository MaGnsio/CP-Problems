/**
 *    author:  MaGnsi0
 *    created: 01.11.2023 14:03:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n; cin >> n;
    int64_t x = __builtin_popcountll(n);
    cout << (1LL << x);
}
