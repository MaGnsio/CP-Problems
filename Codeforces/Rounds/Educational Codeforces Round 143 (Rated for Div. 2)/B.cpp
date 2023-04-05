/**
 *    author:  MaGnsi0
 *    created: 24.02.2023 21:16:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        int x = 0, y = 0, z = 0;
        for (int i = 0; i < n; ++i) {
            int L, R;
            cin >> L >> R;
            x += L == k && R == k;
            y += L == k && R != k;
            z += L != k && R == k;
        }
        cout << (x || (y && z) ? "YES" : "NO") << "\n";
    }
}
