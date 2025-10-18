/**
 *    author:  MaGnsi0
 *    created: 18.10.2025 20:11:39
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        int a; cin >> a;
        int b; cin >> b;
        int d1 = 1, d2 = 1;
        for (int x = 1; x <= a; ++x) {
            for (int y = 1; y <= b; ++y) {
                if (x * y > d1 * d2 && x * y <= b) {
                    d1 = x, d2 = y;
                }
            }
        }
        cout << d1 << " ";
        for (int i = 1; i < n; ++i) { cout << "1 "; }
        cout << d2 << " ";
        for (int i = 1; i < n; ++i) { cout << "1 "; }
        cout << "\n";
    }
}
