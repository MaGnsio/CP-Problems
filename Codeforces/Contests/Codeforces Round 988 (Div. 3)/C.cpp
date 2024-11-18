/**
 *    author:  MaGnsi0
 *    created: 18.11.2024 19:14:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        if (n < 5) {
            cout << "-1\n";
            continue;
        }
        for (int i = 2; i <= n; i += 2) {
            if (i == 4) { continue; }
            cout << i << " ";
        }
        cout << "4 5 ";
        for (int i = 1; i <= n; i += 2) {
            if (i == 5) { continue; }
            cout << i << " ";
        }
        cout << "\n";
    }
}
