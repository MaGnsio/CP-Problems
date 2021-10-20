/**
 *    author:  MaGnsi0
 *    created: 30/07/2021 01:36:16
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int64_t a, b, x = 0;
        cin >> a >> b;
        for (int i = 0; i < 60; ++i) {
            if (!((1LL << i) & a) && ((1LL << i) & b)) {
                x = -1;
                break;
            }
            x |= ((1LL << i) & a) ^ ((1LL << i) & b);
        }
        cout << x << "\n";
    }
}
