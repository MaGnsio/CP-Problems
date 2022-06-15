/**
 *    author:  MaGnsi0
 *    created: 07.06.2022 16:34:08
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
        string s;
        cin >> s;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            a[i]--;
        }
        int64_t ans = 1;
        vector<bool> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            int v = i;
            string t = "";
            while (true) {
                t += s[v];
                visited[v] = true;
                v = a[v];
                if (v == i) {
                    break;
                }
            }
            int64_t x = (int)t.size();
            //try to minimize this cycle
            for (int j = 1; j < x; ++j) {
                if (x % j == 0) {
                    bool ok = true;
                    for (int k = 0; k + j < x; ++k) {
                        ok &= bool(t[k] == t[k + j]);
                    }
                    if (ok) {
                        x = j;
                        break;
                    }
                }
            }
            ans = lcm(ans, x);
        }
        cout << ans << "\n";
    }
}
