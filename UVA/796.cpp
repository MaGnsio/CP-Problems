//https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=737
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& G, vector<bool>& V, vector<int>& in, vector<int>& low, vector<pair<int, int>>& B, int& time, int v, int par = -1) {
    V[v] = true;
    in[v] = low[v] = time++;
    for (auto& u : G[v]) {
        if (u == par) {
            continue;
        }
        if (V[u]) {
            low[v] = min(low[v], in[u]);
        } else {
            dfs(G, V, in, low, B, time, u, v);
            low[v] = min(low[v], low[u]);
            if (low[u] > in[v]) {
                B.push_back({min(u, v), max(u, v)});
            }
        }
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    while (cin >> N) {
        vector<vector<int>> G(N);
        for (int i = 0; i < N; ++i) {
            int u, v, m = 0;
            string s;
            cin >> u >> s;
            for (int j = 1; j < s.size() - 1; ++j) {
                m = m * 10 + s[j] - '0';
            }
            for (int j = 0; j < m; ++j) {
                cin >> v;
                G[u].push_back(v);
            }
        }
        int time = 0;
        vector<int> in(N, 0), low(N, 0);
        vector<pair<int, int>> B;
        vector<bool> V(N, false);
        for (int i = 0; i < N; ++i) {
            if (!V[i]) {
                dfs(G, V, in, low, B, time, i);
            }
        }
        sort(B.begin(), B.end());
        cout << B.size() << " critical links\n";
        for (auto& [x, y] : B) {
            cout << x << " - " << y << "\n";
        }
        cout << "\n";
    }
}
