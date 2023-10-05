/**
 *    author:  MaGnsi0
 *    created: 11.02.2023 17:59:05
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
        if (n % 2 == 0) {
            cout << "NO\n";
        } else {
            int x = 3 * (n + 1) / 2;
            cout << "YES\n";
            for (int i = 1; i <= (n + 1) / 2; ++i) {
                cout << i << " " << x + i - 2 << "\n";
            }
            for (int i = (n + 3) / 2; i <= n; ++i) {
                cout << i << " " << x - (n + 3) + i + 1 << "\n";
            }
        }
    }
}
