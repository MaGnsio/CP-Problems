/**
 *    author:  MaGnsi0
 *    created: 08.06.2022 04:45:06
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        set<pair<int, int>> heads;
        heads.insert(make_pair(0, a[0]));
        for (int i = 1; i < n; ++i) {
            if (a[i] < heads.rbegin() -> second) {
                heads.insert(make_pair(i, a[i]));
            }
        }
        for (int i = 0; i < m; ++i) {
            int k, d;
            cin >> k >> d;
            if (heads.count(make_pair(k - 1, a[k - 1]))) {
                while (true) {
                    auto it = heads.find(make_pair(k - 1, a[k - 1]));
                    if (++it == heads.end() || it -> second < a[k - 1] - d) {
                        break;
                    }
                    heads.erase(it);
                }
                heads.erase(make_pair(k - 1, a[k - 1]));
                a[k - 1] -= d;
                heads.insert(make_pair(k - 1, a[k - 1]));
            } else {
                auto it = heads.lower_bound(make_pair(k - 1, 0));
                assert(it != heads.begin());
                int head = (--it) -> first;
                if (a[k - 1] - d >= a[head]) {
                    a[k - 1] -= d;
                } else {
                    a[k - 1] -= d;
                    heads.insert(make_pair(k - 1, a[k - 1]));
                    while (true) {
                        auto it = heads.find(make_pair(k - 1, a[k - 1]));
                        if (++it == heads.end() || it -> second < a[k - 1]) {
                            break;
                        }
                        heads.erase(it);
                    }
                }
            }
            cout << (int)heads.size() << " ";
        }
        cout << "\n";
    }
}
