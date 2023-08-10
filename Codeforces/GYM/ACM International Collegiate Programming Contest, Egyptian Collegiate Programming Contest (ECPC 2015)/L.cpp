/**
 *    author:  MaGnsi0
 *    created: 20.06.2023 17:19:44
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool Alice = false;
        for (int i = 0; i < n; ++i) {
            int x = a[i] % (n * (n - 1));
            Alice |= x == 0 || x > n - 1;
        }
        cout << (Alice ? "Alice" : "Bob") << "\n";
    }
}
