/**
 *    author:  MaGnsi0
 *    created: 06.01.2024 14:01:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int x = 0; x <= n; ++x) {
        for (int y = 0; y <= n; ++y) {
            for (int z = 0; z <= n; ++z) {
                if (x + y + z > n) { continue; }
                cout << x << " " << y << " " << z << "\n";
            }
        }
    }
}
