/**
 *    author:  MaGnsi0
 *    created: 28.04.2023 21:47:54
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> next(2 * n, -1), last(2 * n, -1);
    for (int i = 0; i < n; ++i) {
        next[i] = n + i;
        last[i] = n + i;
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        if (last[v - 1] == -1) { last[v - 1] = v - 1; }
        next[last[v - 1]] = next[u - 1];
        last[v - 1] = last[u - 1];
        next[u - 1] = last[u - 1] = -1;
    }
    vector<int> ans(n);
    for (int i = 0; i < n; ++i) {
        while (next[i] != -1) {
            ans[next[i] - n] = i;
            next[i] = next[next[i]];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] + 1 << " "[i == n - 1];
    }
}
