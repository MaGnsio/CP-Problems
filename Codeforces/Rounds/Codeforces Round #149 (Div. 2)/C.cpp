/**
 *    author:  MaGnsi0
 *    created: 11/06/2021 20:38:28
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    pair<int, int> a, b;
    cin >> a.first >> a.second >> b.first >> b.second;
    cin >> n;
    map<pair<int, int>, int> m;
    for (int i = 0; i < n; ++i) {
        int x, l, r;
        cin >> x >> l >> r;
        for (int i = l; i <= r; ++i) {
            m[{x, i}] = -1;
        }
    }
    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    queue<int> x, y;
    x.push(a.first), y.push(a.second);
    m[a] = 0;
    while (!x.empty()) {
        int r = x.front(), c = y.front();
        x.pop(), y.pop();
        for (int i = 0; i < 8; ++i) {
            int nr = r + dx[i], nc = c + dy[i];
            if (m[{nr, nc}] == -1) {
                m[{nr, nc}] = m[{r, c}] + 1;
                x.push(nr), y.push(nc);
            }
        }
    }
    cout << m[b];
}
