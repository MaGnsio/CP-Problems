/**
 *    author:  MaGnsi0
 *    created: 04.06.2022 04:09:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    map<int, vector<pair<int, int>>> a;
    for (int i = 0; i < n - 1; ++i) {
        int w, u, v;
        cin >> u >> v >> w;
        a[w].emplace_back(u - 1, v - 1);
    }
    map<int, int64_t> ans;
    for (auto& [x, y] : a) {
        map<int, int64_t> temp;
        for (auto& [u, v] : y) {
            if (temp.count(u)) {
                temp[u]++;
            } else {
                temp[u] = ans[u] + 1;
            }
            temp[u] += ans[v];
            if (temp.count(v)) {
                temp[v]++;
            } else {
                temp[v] = ans[v] + 1; 
            }
            temp[v] += ans[u];
        }
        for (auto& [u, x] : temp) {
            ans[u] = x;
        }
    }
    int64_t res = 0;
    for (auto& [u, x] : ans) {
        res += x;
    }
    cout << res;
}
