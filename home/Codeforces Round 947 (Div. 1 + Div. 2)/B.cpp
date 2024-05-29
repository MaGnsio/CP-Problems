/**
 *    author:  MaGnsi0
 *    created: 28.05.2024 22:29:06
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
        sort(a.begin(), a.end());
        vector<int> b;
        for (int i = 0; i < n; ++i) {
            if (a[i] % a[0]) {
                b.push_back(a[i]);
            }
        }
        int m = (int)b.size();
        bool ok = true; 
        for (int i = 0; i < m; ++i) {
            ok = ok && b[i] % b[0] == 0;
        }
        cout << (ok ? "Yes" : "No") << "\n";
    }
}
