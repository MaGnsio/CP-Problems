/**
 *    author:  MaGnsi0
 *    created: 15.10.2023 21:37:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n; cin >> n;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            cout << __builtin_popcount(x) << " ";
        }
        cout << "\n";
    }
}
