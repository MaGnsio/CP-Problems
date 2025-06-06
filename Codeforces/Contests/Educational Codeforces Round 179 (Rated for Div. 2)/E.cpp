/**
 *    author:  MaGnsi0
 *    created: 06.06.2025 22:00:09
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        string s; cin >> s;
        vector op(3, vector<set<int>>(3));
        for (int i = 0; i < m; ++i) {
            char x; cin >> x;
            char y; cin >> y;
            op[x - 'a'][y - 'a'].insert(i);
        }
        for (int i = 0; i < n; ++i) {
            if (s[i] == 'a') { continue; }
            if (s[i] == 'b') {
                if (!op[1][0].empty()) {
                    s[i] = 'a';
                    op[1][0].erase(op[1][0].begin());
                } else if (!op[1][2].empty()) {
                    int x = *op[1][2].begin();
                    auto it = op[2][0].lower_bound(x);
                    if (it != op[2][0].end()) {
                        s[i] = 'a';
                        op[1][2].erase(x);
                        op[2][0].erase(it);
                    }
                }
            } else if (s[i] == 'c') {
                if (!op[2][0].empty()) {
                    s[i] = 'a';
                    op[2][0].erase(op[2][0].begin());
                } else if (!op[2][1].empty()) {
                    int x = *op[2][1].begin();
                    auto it = op[1][0].lower_bound(x);
                    if (it != op[1][0].end()) {
                        s[i] = 'a';
                        op[2][1].erase(x);
                        op[1][0].erase(it);
                    } else if (!op[2][1].empty()) {
                        s[i] = 'b';
                        op[2][1].erase(op[2][1].begin());
                    }
                }
            }
        }
        cout << s << "\n";
    }
}
