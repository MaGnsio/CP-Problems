/**
 *    author:  MaGnsi0
 *    created: 06.04.2023 16:36:03
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
        if (n & 1) {
            cout << (k & 1 ? "YES" : "NO") << "\n";
        } else {
            cout << "YES\n";
        }
    }
}
