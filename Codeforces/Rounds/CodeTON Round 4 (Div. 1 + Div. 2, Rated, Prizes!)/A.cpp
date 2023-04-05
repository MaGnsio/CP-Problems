/**
 *    author:  MaGnsi0
 *    created: 31.03.2023 16:36:02
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
        bool ok = false;
        for (int i = 0; i < n; ++i) {
            ok |= i + 1 >= a[i];
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
}
