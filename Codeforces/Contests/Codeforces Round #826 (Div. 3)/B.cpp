/**
 *    author:  MaGnsi0
 *    created: 11.10.2022 16:42:04
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
            for (int i = n; i; --i) {
                cout << i << " ";
            }
        } else if (n == 3) {
            cout << -1;
        } else {
            for (int i = n; i > (n + 1) / 2; --i) {
                cout << i << " ";
            }
            for (int i = 1; i <= (n + 1) / 2; ++i) {
                cout << i << " ";
            }
        }
        cout << "\n";
    }
}
