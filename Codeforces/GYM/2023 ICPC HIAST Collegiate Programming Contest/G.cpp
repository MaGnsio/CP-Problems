/**
 *    author:  MaGnsi0
 *    created: 27.08.2023 14:57:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t n;
        cin >> n;
        int64_t x = 1;
        while (2 * x + 1 < n) {
            x = 2 * x + 1;
        }
        cout << x << "\n";
    }
}
