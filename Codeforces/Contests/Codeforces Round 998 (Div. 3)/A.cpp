/**
 *    author:  MaGnsi0
 *    created: 26.01.2025 21:56:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int a1, a2, a4, a5;
        cin >> a1 >> a2 >> a4 >> a5;
        int ans = 0;
        function<void(int)> update = [&](int a3) {
            ans = max(ans, (a1 + a2 == a3) + (a2 + a3 == a4) + (a3 + a4 == a5));
        };
        update(a1 + a2);
        update(a4 - a2);
        update(a5 - a4);
        cout << ans << "\n";
    }
}
