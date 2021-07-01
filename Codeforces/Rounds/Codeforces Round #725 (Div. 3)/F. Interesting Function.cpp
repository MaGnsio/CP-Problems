/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 16:24:00
**/
#include <bits/stdc++.h>
using namespace std;

int F(int n) {
    int res = n - 1;
    for (long long i = 10; i <= 1e9; i *= 10) {
        res += n / i;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        cout << F(r) - F(l) << "\n";
    }
}
