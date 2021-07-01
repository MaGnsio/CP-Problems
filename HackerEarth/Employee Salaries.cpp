//https://www.hackerearth.com/problem/algorithm/problem-2/
#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>>& adj, vector<int>& S, int v) {
    S[v]++;
    for (auto& u : adj[v]) {
        dfs(adj, S, u);
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<vector<int>> adj(N + 1);
        vector<int> S(N + 1, 0), V;
        for (int i = 1; i <= N; ++i) {
            int cnt = 0;
            for (int j = 1; j <= N; ++j) {
                char x;
                cin >> x;
                if (x == 'Y') {
                    adj[j].push_back(i);
                    cnt++;
                }
            }
            if (!cnt) {
                V.push_back(i);
            }
        }
        int total = 0;
        for (auto& v : V) {
            dfs(adj, S, v);
        }
        for (auto& x : S) {
            total += x;
        }
        cout << total << "\n";
    }
}
