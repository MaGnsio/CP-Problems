/**
 *    author:  MaGnsi0
 *    created: 26.05.2025 18:03:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        string s; cin >> s;
        int z = (int)count(s.begin(), s.end(), '0');
        int o = (int)count(s.begin(), s.end(), '1');
        bool ok = false;
        for (int i = 0; 2 * i <= o && i <= k; ++i) {
            int remainingo = o - 2 * i;
            int neededz = 2 * (k - i);
            if (neededz > z) { continue; }
            int remainingz = z - neededz;
            if (remainingz != remainingo) { continue; }
            ok = true;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
