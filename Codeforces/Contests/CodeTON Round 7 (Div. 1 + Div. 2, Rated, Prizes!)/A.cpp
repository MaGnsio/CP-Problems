/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 16:51:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        cout << (a[0] == 1 ? "YES" : "NO") << "\n";
    }
}
