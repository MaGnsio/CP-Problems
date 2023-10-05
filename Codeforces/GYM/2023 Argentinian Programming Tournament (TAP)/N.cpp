/**
 *    author:  MaGnsi0
 *    created: 21.09.2023 11:49:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> mod5(5, 0);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        mod5[x % 5]++;
    }
    int ans = 0;
    ans += mod5[0], mod5[0] = 0;
    int x = min(mod5[1], mod5[4]);
    ans += x, mod5[1] -= x, mod5[4] -= x;
    int y = min(mod5[2], mod5[3]);
    ans += y, mod5[2] -= y, mod5[3] -= y;
    if (mod5[1] && mod5[2]) {
        int z = min(mod5[1], mod5[2] / 2);
        ans += z, mod5[1] -= z, mod5[2] -= 2 * z;
        if (mod5[2] && mod5[1] >= 3) {
            ans++, mod5[1] -= 3, mod5[2] = 0;
        }
    } else if (mod5[1] && mod5[3]) {
        int z = min(mod5[1] / 2, mod5[3]);
        ans += z, mod5[1] -= 2 * z, mod5[3] -= z;
        if (mod5[1] && mod5[3] >= 3) {
            ans++, mod5[1] = 0, mod5[3] -= 3;
        }
    } else if (mod5[4] && mod5[2]) {
        int z = min(mod5[4] / 2, mod5[2]);
        ans += z, mod5[4] -= 2 * z, mod5[2] -= z;
        if (mod5[4] && mod5[2] >= 3) {
            ans++, mod5[4] = 0, mod5[2] -= 3;
        }
    } else if (mod5[4] && mod5[3]) {
        int z = min(mod5[4], mod5[3] / 2);
        ans += z, mod5[4] -= z, mod5[3] -= 2 * z;
        if (mod5[3] && mod5[4] >= 3) {
            ans++, mod5[4] -= 3, mod5[3] = 0;
        }
    }
    for (int i = 1; i < 5; ++i) {
        ans += mod5[i] / 5;
    }
    cout << ans;
}
