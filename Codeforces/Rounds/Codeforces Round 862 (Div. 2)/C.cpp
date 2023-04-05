/**
 *    author:  MaGnsi0
 *    created: 02.04.2023 16:56:05
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
        vector<int64_t> k(n);
        for (int i = 0; i < n; ++i) {
            cin >> k[i];
        }
        set<int64_t> s_pos(k.begin(), k.end()), s_neg;
        for (int i = 0; i < n; ++i) {
            s_neg.insert(-k[i]);
        }
        for (int i = 0; i < m; ++i) {
            int64_t a, b, c;
            cin >> a >> b >> c;
            int64_t y = int64_t(4) * a * c;
            auto it1 = s_pos.lower_bound(b);
            auto it2 = s_neg.lower_bound(-b);
            if (it1 != s_pos.end() && (b - *it1) * (b - *it1) - y < 0) {
                cout << "YES\n";
                cout << *it1 << "\n";
            } else if (it2 != s_neg.end() && (b + *it2) * (b + *it2) - y < 0) {
                cout << "YES\n";
                cout << -*it2 << "\n";
            } else {
                cout << "NO\n";
            }
        }
        cout << "\n";
    }
}
