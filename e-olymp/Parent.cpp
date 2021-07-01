//https://www.e-olymp.com/en/contests/13708/problems/133545
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& G, vector<int>& in, vector<int>& out, int& time, int v) {
    in[v] = time++;
    for (auto& u : G[v]) {
        dfs(G, in, out, time, u);
    }
    out[v] = time++;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, Q, start, time = 0;
    cin >> N;
    vector<vector<int>> G(N + 1);
    vector<int> in(N + 1), out(N + 1);
    for (int u = 1; u <= N; ++u) {
        int v;
        cin >> v;
        if (!v) {
            start = u;
            continue;
        }
        G[v].push_back(u);
    }
    dfs(G, in, out, time, start);
    cin >> Q;
    while (Q--) {
        int p, c;
        cin >> p >> c;
        cout << (in[p] < in[c] && out[p] > in[c] ? 1 : 0) << "\n";
    }
}
