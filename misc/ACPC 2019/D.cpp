/**
 *    author:  MaGnsi0
 *    created: 23.07.2023 14:43:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("dimension35c.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(a.begin(), a.end());
        vector<double> ans(n);
        for (int i = 0; i < n; ++i) {
            ans[a[i].second] = a[i].first;
            for (int j = i + 1, k = 2; j < n; ++j, ++k) {
                ans[a[i].second] += 1.0 * a[j].first / k;
            }
            for (int j = i - 1, k = 2; j >= 0; --j, ++k) {
                ans[a[i].second] += 1.0 * a[j].first / k;
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << fixed << setprecision(6) << ans[i] << " ";
        }
        cout << "\n";
    }
}
