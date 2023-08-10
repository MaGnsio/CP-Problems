/**
 *    author:  MaGnsi0
 *    created: 27.05.2023 15:09:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    cin >> s;
    set<pair<int, int>> s_;
    for (int i = 0; i < m; ++i) {
        int x, y;
        cin >> x >> y;
        s_.emplace(x, y);
    }
    int x = 0, y = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'U') { y++; }
        if (s[i] == 'D') { y--; }
        if (s[i] == 'R') { x++; }
        if (s[i] == 'L') { x--; }
        h--;
        if (i != n - 1 && h < 0) {
            cout << "No";
            return 0;
        }
        if (s_.count(make_pair(x, y)) && h < k) {
            s_.erase(make_pair(x, y));
            h = k;
        }
        if (i != n - 1 && h <= 0) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}
