/**
 *    author:  MaGnsi0
 *    created: 10.03.2022 16:30:28
**/
#include <bits/stdc++.h>

using namespace std;

int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first >> a[i].second;
    }
    set<pair<int, int>> s(a.begin(), a.end());
    map<pair<int, int>, pair<int, int>> ans;
    queue<pair<int, int>> q;
    for (auto& [x, y] : s) {
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (s.count({nx, ny})) {
                continue;
            }
            q.push({x, y});
            ans[{x, y}] = {nx, ny};
            break;
        }
    }
    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; ++i) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!s.count({nx, ny}) || ans.count({nx, ny})) {
                continue;
            }
            q.push({nx, ny});
            ans[{nx, ny}] = ans[{x, y}];
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[a[i]].first << " " << ans[a[i]].second << "\n";
    }
}
