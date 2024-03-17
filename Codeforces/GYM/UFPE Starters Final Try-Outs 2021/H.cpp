/**
 *    author:  MaGnsi0
 *    created: 10.02.2024 15:04:19
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 3;

const int dx[4] = {-1, 0, 0, 1};
const int dy[4] = {0, -1, 1, 0};

typedef array<array<int, N>, N> state;

const state O = {1, 2, 3, 4, 5, 6, 7, 8, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    state a;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> a[i][j];
        }
    }
    vector<int64_t> cost(N * N);
    for (int i = 1; i < N * N; ++i) {
        cin >> cost[i];
    }
    map<state, int64_t> ans;
    set<pair<int64_t, state>> S;
    ans[O] = 0; S.emplace(0, O);
    while (!S.empty()) {
        auto [dv, v] = *S.begin();
        S.erase(S.begin());
        if (ans.count(v) && dv != ans[v]) { continue; }
        int x, y;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (v[i][j] == 0) {
                    x = i, y = j;
                }
            }
        }
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= N) { continue; }
            if (ny < 0 || ny >= N) { continue; }
            state u = v;
            swap(u[x][y], u[nx][ny]);
            if (ans.count(u) && ans[v] + cost[v[nx][ny]] >= ans[u]) { continue; }
            ans[u] = ans[v] + cost[v[nx][ny]];
            S.emplace(ans[u], u);
        }
    }
    cout << ans[a];
}
