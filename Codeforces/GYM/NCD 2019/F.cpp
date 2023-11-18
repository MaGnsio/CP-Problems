/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 21:38:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n, k;
        cin >> n >> k;
        assert(n >= k);
        cout << (n - k + 5) / 6 << "\n";
    }
}
