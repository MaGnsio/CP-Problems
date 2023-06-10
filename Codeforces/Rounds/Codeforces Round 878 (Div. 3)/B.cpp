/**
 *    author:  MaGnsi0
 *    created: 07.06.2023 03:50:38
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k > 30) {
            cout << n + 1 << "\n";
        } else {
            cout << min(n + 1, 1 << k) << "\n";
        }
    }
}
