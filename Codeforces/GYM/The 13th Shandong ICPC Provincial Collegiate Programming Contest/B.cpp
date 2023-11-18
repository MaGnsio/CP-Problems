/**
 *    author:  MaGnsi0
 *    created: 13.10.2023 20:53:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    map<int, int64_t> employees;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        int64_t y; cin >> y;
        employees[x] = y;
    }
    int m; cin >> m;
    vector<int> projectBlock(m);
    map<int, vector<pair<int64_t, int>>> needs;
    vector<vector<pair<int, int64_t>>> projectAdd(m);
    for (int i = 0; i < m; ++i) {
        int k1; cin >> k1;
        projectBlock[i] = k1;
        for (int j = 0; j < k1; ++j) {
            int x; cin >> x;
            int64_t y; cin >> y;
            needs[x].emplace_back(y, i);
        }
        int k2; cin >> k2;
        for (int j = 0; j < k2; ++j) {
            int x; cin >> x;
            int64_t y; cin >> y;
            projectAdd[i].emplace_back(x, y);
        }
    }
    int ans = 0;
    queue<int> Q;
    for (auto& [_, a] : needs) {
        sort(a.rbegin(), a.rend());
    }
    for (auto& [x, y] : employees) {
        while (!needs[x].empty() && needs[x].back().first <= y) {
            int j = needs[x].back().second;
            projectBlock[j]--;
            needs[x].pop_back();
        }
    }
    for (int j = 0; j < m; ++j) {
        if (projectBlock[j] == 0) { Q.push(j); }
    }
    while (!Q.empty()) {
        int p = Q.front(); Q.pop(); ans++;
        for (auto& [x, y] : projectAdd[p]) {
            employees[x] += y;
            while (!needs[x].empty() && needs[x].back().first <= employees[x]) {
                int j = needs[x].back().second;
                projectBlock[j]--;
                if (projectBlock[j] == 0) { Q.push(j); }
                needs[x].pop_back();
            }
        }
    }
    cout << ans;
}
