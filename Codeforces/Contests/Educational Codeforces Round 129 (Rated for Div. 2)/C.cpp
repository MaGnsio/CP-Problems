/**
 *    author:  MaGnsi0
 *    created: 23.05.2022 16:51:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        vector<tuple<int, int, int>> c(n);
        for (int i = 0; i < n; ++i) {
            c[i] = make_tuple(a[i], b[i], i);
        }
        sort(c.begin(), c.end());
        bool ok = true;
        for (int i = 1; i < n; ++i) {
            if (get<0>(c[i]) < get<0>(c[i - 1]) || get<1>(c[i]) < get<1>(c[i - 1])) {
                ok = false;
            }
        }
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        vector<int> cur_index(n);
        vector<pair<int, int>> ans;
        for (int i = 0; i < n; ++i) {
            cur_index[i] = i;
        }
        for (int i = 0; i < n; ++i) {
            if (cur_index[get<2>(c[i])] == i) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (cur_index[j] == i) {
                    ans.push_back(make_pair(cur_index[get<2>(c[i])], cur_index[j]));
                    swap(cur_index[get<2>(c[i])], cur_index[j]);
                    break;
                }
            }
        }
        cout << (int)ans.size() << "\n";
        for (int i = 0; i < (int)ans.size(); ++i) {
            cout << ans[i].first + 1 << " " << ans[i].second + 1 << "\n";
        }
    }
}
