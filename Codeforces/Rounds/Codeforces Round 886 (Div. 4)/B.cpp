/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 17:38:05
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
        int ans = 0, max_b = 0;
        for (int i = 0; i < n; ++i) {
            int a, b;
            cin >> a >> b;
            if (a > 10) { continue; }
            if (b > max_b) { ans = i + 1, max_b = b; }
        }
        cout << ans << "\n";
    }
}
