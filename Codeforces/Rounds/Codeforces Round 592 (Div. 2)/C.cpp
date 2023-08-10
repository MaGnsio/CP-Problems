/**
 *    author:  MaGnsi0
 *    created: 19.06.2023 19:42:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t n, p, w, d;
    cin >> n >> p >> w >> d;
    for (int64_t y = 0; y <= w; ++y) {
        if ((p - y * d) % w) { continue; }
        int64_t x = (p - y * d) / w;
        if (x < 0 || x + y > n) { continue; }
        int64_t z = n - x - y;
        cout << x << " " << y << " " << z << "\n";
        return 0;
    }
    cout << -1;
}
