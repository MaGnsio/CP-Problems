/**
 *    author:  MaGnsi0
 *    created: 18/09/2021 19:11:59
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int d, n, k;
        cin >> d >> n >> k;
        vector<pair<int, pair<int, int>>> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].first >> v[i].second.first >> v[i].second.second;
        }
        sort(v.begin(), v.end());
        reverse(v.begin(), v.end());
        vector<int> res(d + 1, 0), cnt(d + 1, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = v[i].second.first; j <= v[i].second.second; ++j) {
                if (cnt[j] < k) {
                    res[j] += v[i].first;
                    cnt[j]++;
                }
            }
        }
        cout << "Case #" << t << ": " << *max_element(res.begin(), res.end()) << "\n";
    }
}
