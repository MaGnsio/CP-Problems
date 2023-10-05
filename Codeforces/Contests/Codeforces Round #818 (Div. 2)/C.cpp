/**
 *    author:  MaGnsi0
 *    created: 02.09.2022 16:33:21
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int j = 0; j < n; ++j) {
            cin >> b[j];
        }
        function<bool(int)> can = [&](int j) {
            return (a[j] <= b[j] && ((a[j] <= b[(j + 1) % n] && b[j] <= b[(j + 1) % n] + 1) || a[j] == b[j]));
        };
        vector<bool> visited(n, false);
        function<void(int)> dfs = [&](int v) {
            visited[v] = true;
            if (!visited[(v - 1 + n) % n] && can((v - 1 + n) % n)) {
                dfs((v - 1 + n) % n);
            }
        };
        for (int i = 0; i < n; ++i) {
            if (!visited[i] && can(i)) {
                dfs(i);
            }
        }
        cout << (count(visited.begin(), visited.end(), true) == n ? "YES" : "NO") << "\n";
    }
}
