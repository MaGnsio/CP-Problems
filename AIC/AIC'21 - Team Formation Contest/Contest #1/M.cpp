/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:56
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<vector<int>> adj(n + 1);
    for (int v = 2, u; v <= n; ++v) {
        cin >> u;
        adj[u].push_back(v);
    }
    vector<int> dis(n + 1, -1);
    queue<int> q;
   q.push(1);
   dis[1] = 0;
   while(!q.empty()) {
       int v = q.front();
       q.pop();
       for (auto& u : adj[v]) {
           if (dis[u] == -1) {
               dis[u] = dis[v] + 1;
               q.push(u);
           }
       }
   }
   map<int, int> m;
   for (int i = 2; i <= n; ++i) {
       m[dis[i]]++;
   }
   int ans = 0;
   for (auto& [x, y] : m) {
       ans += (y % 2);
   }
   cout << ans + 1;
}
