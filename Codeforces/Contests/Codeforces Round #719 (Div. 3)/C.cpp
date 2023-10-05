/**
 *    author:  MaGnsi0
 *    created: 12.02.2023 20:11:44
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
        if (n == 2) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0, x = 1; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                cout << x << " ";
                if (x + 2 > n * n) {
                    x = 2;
                } else {
                    x += 2;
                }
            }
            cout << "\n";
        }
    }
}
