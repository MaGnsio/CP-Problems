/**
 *    author:  MaGnsi0
 *    created: 06.01.2024 14:05:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    deque<pair<int, int>> parts;
    for (int i = 1; i <= n; ++i) {
        parts.emplace_back(i, 0);
    }
    while (Q--) {
        int t; cin >> t;
        if (t == 1) {
            char c; cin >> c;
            int x = parts.front().first;
            int y = parts.front().second;
            if (c == 'U') {
                y++;
            } else if (c == 'D') {
                y--;
            } else if (c == 'L') {
                x--;
            } else {
                x++;
            }
            parts.pop_back();
            parts.emplace_front(x, y);
        } else {
            int j; cin >> j; j--;
            cout << parts[j].first << " " << parts[j].second << "\n";
        }
    }
}
