/**
 *    author:  MaGnsi0
 *    created: 16.07.2022 16:33:22
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
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            bool can = false;
            for (int j = 0; j < i; ++j) {
                can |= (a[i] % a[j] == 0);
            }
            ok &= can;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
