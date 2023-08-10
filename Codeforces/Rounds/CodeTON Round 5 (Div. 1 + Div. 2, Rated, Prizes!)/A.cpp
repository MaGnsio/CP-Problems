/**
 *    author:  MaGnsi0
 *    created: 24.06.2023 17:07:08
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < m; ++i) {
            cin >> b[i];
        }
        int turn = 0;
        multiset<int> s(a.begin(), a.end());
        multiset<int> t(b.begin(), b.end());
        while (!s.empty() && !t.empty()) {
            if (turn == 0) {
                int x = *s.rbegin();
                int y = *t.begin();
                s.erase(s.find(x));
                t.erase(t.find(y));
                if (x > y) {
                    s.insert(x - y);
                } else if (x < y) {
                    t.insert(y - x);
                }
            } else {
                int x = *s.begin();
                int y = *t.rbegin();
                s.erase(s.find(x));
                t.erase(t.find(y));
                if (x > y) {
                    s.insert(x - y);
                } else if (x < y) {
                    t.insert(y - x);
                }
            }
            turn ^= 1;
        }
        if (s.empty() && t.empty()) {
            cout << "Draw\n";
        } else if (s.empty()) {
            cout << "Tenzing\n";
        } else {
            cout << "Tsondu\n";
        }
    }
}
