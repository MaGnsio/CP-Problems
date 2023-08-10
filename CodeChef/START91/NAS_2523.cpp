/**
 *    author:  MaGnsi0
 *    created: 24.05.2023 17:31:12
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
        if (n & 1) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = n; i >= 1; --i) {
            cout << i << " ";
        }
        cout << "\n";
    }
}
