/**
 *    author:  MaGnsi0
 *    created: 02.03.2023 20:57:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        string s, t;
        cin >> s >> t;
        vector<bool> visited(n, false);
        string x, y;
        function<void(int)> dfs = [&](int v) {
            visited[v] = true;
            x += s[v], y += t[v];
            if (v + k < n && !visited[v + k]) {
                dfs(v + k);
            }
            if (v + k + 1 < n && !visited[v + k + 1]) {
                dfs(v + k + 1);
            }
            if (v - k >= 0 && !visited[v - k]) {
                dfs(v - k);
            }
            if (v - k - 1 >= 0 && !visited[v - k - 1]) {
                dfs(v - k - 1);
            }
        };
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            if (visited[i]) { continue; }
            x = "", y = "";
            dfs(i);
            sort(x.begin(), x.end());
            sort(y.begin(), y.end());
            ok &= x == y;
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
