//https://www.e-olymp.com/en/contests/8063/problems/67701
#include <bits/stdc++.h>
using namespace std;

bool dfs(vector<set<int>>& adj, vector<int>& color, int v) {
    color[v] = 1;
    for (auto& u : adj[v]) {
        if (color[v] == 2) {
            continue;
        }
        if (color[u] == 1) {
            return true;
        }
        if (dfs(adj, color, u)) {
            return true;
        }
    }
    color[v] = 2;
    return false;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    while ((cin >> N) && N) {
        vector<string> S(N);
        for (auto& s : S) {
            cin >> s;
        }
        bool ok = true;
        vector<set<int>> adj(26);
        vector<int> color(26, 0);
        for (int i = 1; i < N; ++i) {
            bool chk = true;
            for (int j = 0; j < min(S[i].size(), S[i - 1].size()); ++j) {
                if (S[i][j] != S[i - 1][j]) {
                    adj[S[i - 1][j] - 'a'].insert(S[i][j] - 'a');
                    chk = false;
                    break;
                }
            }
            if (chk && S[i].size() < S[i - 1].size()) {
                ok = false;
                break;
            }
        }
        if (ok == false) {
            cout << "no\n";
            continue;
        }
        for (int i = 0; i < 26; ++i) {
            if (color[i] == 0 && dfs(adj, color, i)) {
                ok = false;
                break;
            }
        }
        cout << (ok ? "yes\n" : "no\n");
    }
}
