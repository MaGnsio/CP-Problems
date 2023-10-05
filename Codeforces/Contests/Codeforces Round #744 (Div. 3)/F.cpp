/**
 *    author:  MaGnsi0
 *    created: 29/09/2021 15:48:18
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, d;
        cin >> n >> d;
        vector<int> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i];
        }
        int res = 0;
        vector<int> visited(n, false);
        for (int i = 0; i < n; ++i) {
            if (visited[i]) {
                continue;
            }
            vector<int> cycle;
            for (int j = i; !visited[j]; j = (j + n - d) % n) {
                cycle.push_back(v[j]);
                visited[j] = true;
            }
            if (count(cycle.begin(), cycle.end(), 0) == 0) {
                res = -1;
                break;
            }
            int m = (int)cycle.size();
            for (int j = 0; j < m; ++j) {
                cycle.push_back(cycle[j]);
            }
            reverse(cycle.begin(), cycle.end());
            for (int j = 0, last_zero = -1; j < (int)cycle.size(); ++j) {
                if (!cycle[j]) {
                    last_zero = j;
                    continue;
                }
                if (cycle[j] && j >= m) {
                    res = max(res, j - last_zero);
                }
            }
        }
        cout << res << "\n";
    }
}
