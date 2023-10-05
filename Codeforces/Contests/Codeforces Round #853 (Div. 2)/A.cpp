/**
 *    author:  MaGnsi0
 *    created: 25.02.2023 16:22:44
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
            for (int j = 0; j < i; ++j) {
                ok = ok || __gcd(a[i], a[j]) <= 2;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
