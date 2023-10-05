/**
 *    author:  MaGnsi0
 *    created: 12/09/2021 16:29:24
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> v(n * m);
        for (int i = 0; i < n * m; ++i) {
            cin >> v[i].first;
            v[i].second = i;
        }
        sort(v.begin(), v.end());
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i * m; j < (i + 1) * m; ++j) {
                for (int k = j - 1; k >= i * m; --k) {
                    if (v[k].first < v[j].first && v[k].second < v[j].second) {
                        res++;
                    }
                }
            }
        }
        cout << res << "\n";
    }
}
