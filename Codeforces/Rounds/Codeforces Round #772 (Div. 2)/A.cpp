/**
 *    author:  MaGnsi0
 *    created: 20.02.2022 16:26:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        long long res = 0;
        for (int i = 0; i < n; ++i) {
            long long x;
            cin >> x;
            res |= x;
        }
        cout << res << "\n";
    }
}
