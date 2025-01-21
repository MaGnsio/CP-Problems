/**
 *    author:  MaGnsi0
 *    created: 21.01.2025 19:34:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int odd = 0, even = 0;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            odd += (x & 1);
            even += !(x & 1);
        }
        cout << max((even > 0) * (odd + 1), odd - 1) << "\n";
    }
}
