/**
 *    author:  MaGnsi0
 *    created: 28.11.2022 11:38:43
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
            for (int i = 0; i < n; ++i) {
                cout << 1 << " ";
            }
        } else {
            cout << 1 << " " << 3 << " ";
            for (int i = 0; i < n - 2; ++i) {
                cout << 2 << " ";
            }
        }
        cout << "\n";
    }
}
