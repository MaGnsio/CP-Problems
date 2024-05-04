/**
 *    author:  MaGnsi0
 *    created: 22.04.2024 10:25:00
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 105;

int main() {
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(N);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; a[x]++;
        }
        int ans = 0;
        for (int y : a) {
            ans += y / 3;
        }
        cout << ans << "\n";
    }
}
