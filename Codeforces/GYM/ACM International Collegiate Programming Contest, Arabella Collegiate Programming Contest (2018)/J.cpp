/**
 *    author:  MaGnsi0
 *    created: 05.09.2022 21:14:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        cout << n + 1 - (int64_t(1) << __builtin_popcountll(n)) << "\n";
    }
}
