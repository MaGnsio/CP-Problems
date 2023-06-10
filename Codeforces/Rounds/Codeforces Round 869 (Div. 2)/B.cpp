/**
 *    author:  MaGnsi0
 *    created: 04.05.2023 18:10:40
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
        if (n == 1) {
            cout << 1 << "\n";
        } else if (n & 1) {
            cout << -1 << "\n";
        } else {
            for (int i = 2; i <= n; i += 2) {
                cout << i << " " << i - 1 << " ";
            }
            cout << "\n";
        }
    }
}
