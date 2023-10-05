/**
 *    author:  MaGnsi0
 *    created: 26.11.2021 13:02:27
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
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i].first;
            a[i].second = i + 1;
        }
        sort(a.begin(), a.end(), greater<pair<int, int>>());
        long long cost = 0;
        vector<int> res(n + 1, 0);
        for (int i = 0, j = 1; i < n; ++i) {
            res[a[i].second] = j;
            if (i & 1) {
                res[a[i].second] *= -1;
                j++;
            }
            cost += 2LL * abs(res[a[i].second]) * a[i].first;
        }
        cout << cost << "\n";
        for (int i = 0; i <= n; ++i) {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
