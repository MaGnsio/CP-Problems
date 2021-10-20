/**
 *    author:  MaGnsi0
 *    created: 04/08/2021 05:24:30
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxN = 1e6 + 6;

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        int c, m;
        cin >> c >> m;
        vector<int> f(maxN, 0);
        for (int i = 0; i < c; ++i) {
            int x;
            cin >> x;
            f[x]++;
        }
        vector<pair<int, int>> v;
        for (int i = 0; i < maxN; ++i) {
            if (!f[i]) {
                continue;
            }
            v.push_back({f[i] * i, i});
        }
        sort(v.begin(), v.end(), greater<pair<int, int>>());
        int sum = 0;
        vector<int> ans;
        for (auto& [x, y] : v) {
            sum += x;
            ans.push_back(y);
            if (sum >= m) {
                break;
            }
        }
        if (sum < m) {
            cout << "Impossible";
        } else {
            sort(ans.begin(), ans.end());
            for (auto& x : ans) {
                cout << x << " ";
            }
        }
        cout << "\n";
    }
}
