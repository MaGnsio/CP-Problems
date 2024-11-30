/**
 *    author:  MaGnsi0
 *    created: 30.11.2024 16:35:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int a; cin >> a;
        int b; cin >> b;
        int ans = min(a, b);
        while (true) {
            if ((ans % a) == (ans % b)) {
                cout << ans << "\n";
                break;
            }
            ans++;
        }
    }
}
