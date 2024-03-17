/**
 *    author:  MaGnsi0
 *    created: 25.11.2023 15:08:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
        }
        for (int i = 0; i < n; ++i) {
            cin >> a[i].second;
        }
        sort(a.begin(), a.end());
        int m; cin >> m;
        vector<pair<int, int>> b(m);
        for (int i = 0; i < m; ++i) {
            cin >> b[i].first;
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i].second;
        }
        sort(b.begin(), b.end());
        vector<pair<int, int>> sufA(n), sufB(m);
        sufA[n - 1] = make_pair(a[n - 1].second, n - 1);
        for (int i = n - 2; i >= 0; --i) {
            sufA[i] = max(sufA[i + 1], make_pair(a[i].second, i));
        }
        sufB[m - 1] = make_pair(b[m - 1].second, m - 1);
        for (int i = m - 2; i >= 0; --i) {
            sufB[i] = max(sufB[i + 1], make_pair(b[i].second, i));
        }
        vector<vector<int>> result(2);
        result[0] = vector<int>(n);
        result[1] = vector<int>(m);
        vector<vector<bool>> visited(2);
        visited[0] = vector<bool>(n);
        visited[1] = vector<bool>(m);
        function<int(int, int)> best = [&](int x, int v) {
            if (x == 0) {
                int low = 0, high = m - 1, j = -1;
                while (low <= high) {
                    int mid = (low + high) / 2;
                    if (b[mid].first > a[v].second) {
                        j = mid, high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                }
                return (j == -1 ? -1 : sufB[j].second);
            }
            int low = 0, high = n - 1, j = -1;
            while (low <= high) {
                int mid = (low + high) / 2;
                if (a[mid].first > b[v].second) {
                    j = mid, high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            return (j == -1 ? -1 : sufA[j].second);
        };
        function<void(int, int)> dfs = [&](int x, int v) {
            visited[x][v] = true;
            int u = best(x, v);
            if (u != -1) {
                if (!visited[x ^ 1][u]) { dfs(x ^ 1, u); }
                result[x][v] = -result[x ^ 1][u];
            } else {
                result[x][v] = 1;
            }
        };
        for (int i = 0; i < n; ++i) {
            if (visited[0][i]) { continue; }
            dfs(0, i);
        }
        tuple<int, int, int> ans = {0, n, 0};
        for (int i = 0; i < n; ++i) {
            get<0>(ans) += result[0][i] == 1;
            get<1>(ans) -= result[0][i] != 0;
            get<2>(ans) += result[0][i] == -1;
        }
        cout << get<0>(ans) << " " << get<1>(ans) << " " << get<2>(ans) << "\n";
    }
}
