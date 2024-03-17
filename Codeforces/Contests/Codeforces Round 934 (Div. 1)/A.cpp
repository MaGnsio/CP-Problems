/**
 *    author:  MaGnsi0
 *    created: 16.03.2024 22:38:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n + 1);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x;
            if (x > n) { continue; }
            a[x]++;
        }
        bool found_one = false;
        for (int i = 0; i <= n; ++i) {
            if (a[i] == 0 || (found_one && a[i] == 1)) {
                cout << i << "\n";
                break;
            }
            found_one |= a[i] == 1;
        }
    }
}
