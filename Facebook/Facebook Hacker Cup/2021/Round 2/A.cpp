/**
 *    author:  MaGnsi0
 *    created: 25/09/2021 18:55:34
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i].first;
            a[i].second = 1;
        }
        int res = 0;
        for (int round = 0; round < n; ++round) {
            vector<int> b(m);
            for (int i = 0; i < m; ++i) {
                cin >> b[i];
            }
            sort(a.begin(), a.end());
            sort(b.begin(), b.end());
            int first_time = 0, cnt = 0;
            vector<pair<int, int>> c;
            int i = 0, j = 0;
            while ((i < m) || (j < m)) {
                if ((i < m) && (j < m) && (a[i].first == b[j])) {
                    c.push_back(a[i]);
                    i++, j++;
                    continue;
                }
                if ((j == m) || ((i < m) && (a[i].first < b[j]))) {
                    first_time += a[i].second;
                    i++;
                } else {
                    cnt++;
                    c.push_back({b[j], 0});
                    j++;
                }
            }
            assert(cnt >= first_time);
            res += (cnt - first_time);
            assert((int)c.size() == m);
            swap(a, c);
        }
        cout << "Case #" << t << ": " << res << "\n";
    }
}
