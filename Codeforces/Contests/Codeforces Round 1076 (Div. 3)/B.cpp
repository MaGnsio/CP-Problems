/**
 *    author:  MaGnsi0
 *    created: 25.01.2026 16:37:59
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
        int x = n;
        int s = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) { x--; s++; }
            else { break; }
        }
        for (int i = 0; i < n; ++i) {
            if (a[i] == x) {
                reverse(a.begin() + s, a.begin() + i + 1);
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
}
