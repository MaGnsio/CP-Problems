/**
 *    author:  MaGnsi0
 *    created: 03.02.2023 17:40:17
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<int> s;
        for (int i = 0; i < n; ++i) {
            s.insert(i);
        }
        for (int i = 0; i < q; ++i) {
            int t;
            cin >> t;
            if (t == 1) {
                int l, r;
                cin >> l >> r;
                int cur_l = l - 1;
                while (true) {
                    auto it = s.lower_bound(cur_l);
                    if (it == s.end() || *it >= r) {
                        break;
                    }
                    int j = *it;
                    string _s = to_string(a[j]);
                    a[j] = 0;
                    for (auto& c : _s) {
                        a[j] += c - '0';
                    }
                    cur_l = j + 1;
                    if (to_string(a[j]).size() == 1) {
                        s.erase(it);
                    }
                }
            } else {
                int x;
                cin >> x;
                cout << a[x - 1] << "\n";
            }
        }
    }
}
