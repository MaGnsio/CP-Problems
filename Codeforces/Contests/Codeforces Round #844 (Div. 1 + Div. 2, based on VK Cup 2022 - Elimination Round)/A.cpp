/**
 *    author:  MaGnsi0
 *    created: 15.01.2023 14:14:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int w, d, h;
        cin >> w >> d >> h;
        int a, b, f, g;
        cin >> a >> b >> f >> g;
        int ans = a + h + f + abs(b - g);
        ans = min(ans, w - a + h + abs(w - f) + abs(b - g)); 
        ans = min(ans, b + h + abs(a - f) + g);
        ans = min(ans, d - b + h + abs(a - f) + abs(d - g));
        cout << ans << "\n";
    }
}
