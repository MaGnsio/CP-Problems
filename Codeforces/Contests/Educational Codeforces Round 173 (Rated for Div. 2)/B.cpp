/**
 *    author:  MaGnsi0
 *    created: 24.12.2024 16:45:57
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int64_t n; cin >> n;
        int64_t d; cin >> d;
        cout << 1 << " ";
        if (n >= 3 || d % 3 == 0) {
            cout << 3 << " ";
        }
        if (d == 5) {
            cout << 5 << " ";
        }
        if (n >= 3 || stoi(string(n, char('0' + d))) % 7 == 0) {
            cout << 7 << " ";
        }
        if (n >= 6 || d % 9 == 0 || (n >= 3 && d % 3 == 0)) {
            cout << 9 << " ";
        }
        cout << "\n";
    }
}
