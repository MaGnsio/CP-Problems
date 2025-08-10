/**
 *    author:  MaGnsi0
 *    created: 10.08.2025 17:51:20
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //3 5
    //6 2 9
    //6 => 1, 4, 9, ...
    //2 => 2, 3, 7, ...
    //9 => 1, 4, 9
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        map<int, int> a, b;
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; x %= k;
            x = min(x, k - x);
            a[x]++;
        }
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; x %= k;
            x = min(x, k - x);
            b[x]++;
        }
        cout << (a == b ? "YES" : "NO") << "\n";
    }
}
