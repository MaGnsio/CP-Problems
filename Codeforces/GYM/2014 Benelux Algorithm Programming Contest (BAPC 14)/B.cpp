/**
 *    author:  MaGnsi0
 *    created: 17.11.2021 17:41:22
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 3600 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, t;
        cin >> n >> t;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int> d(N, -1);
        queue<pair<int, int>> q;
        d[0] = 0;
        q.push({0, 0});
        while (!q.empty()) {
            int v = q.front().first;
            int d_v = q.front().second;
            q.pop();
            for (int i = 0; i < n; ++i) {
                int u = v + a[i];
                u = max(u, 0);
                u = min(u, 3600);
                if (d[u] != -1) {
                    continue;
                }
                d[u] = d_v + 1;
                q.push({u, d[u]});
            }
        }
        int x, y;
        for (int i = t; i < N; ++i) {
            if (d[i] == -1) {
                continue;
            }
            x = d[i], y = i - t;
            break;
        }
        cout << x << " " << y << "\n";
    }
}
