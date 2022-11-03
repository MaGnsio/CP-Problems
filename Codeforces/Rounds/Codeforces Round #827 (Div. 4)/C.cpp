/**
 *    author:  MaGnsi0
 *    created: 14.10.2022 19:36:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n = 8;
        vector<string> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        bool R = false;
        for (int i = 0; i < n; ++i) {
            R |= count(a[i].begin(), a[i].end(), 'R') == n;
        }
        cout << (R ? "R" : "B") << "\n";
    }
}
