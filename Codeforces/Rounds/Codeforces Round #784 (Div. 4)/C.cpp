/**
 *    author:  MaGnsi0
 *    created: 22.04.2022 09:57:30
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
        int O = 0, cntO = 0, E = 0, cntE = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) {
                O += (a[i] % 2);
                cntO++;
            } else {
                E += (a[i] % 2);
                cntE++;
            }
        }
        cout << ((O == cntO || O == 0) && (E == cntE || E == 0) ? "YES" : "NO") << "\n";
    }
}
