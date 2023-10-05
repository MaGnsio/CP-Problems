/**
 *    author:  MaGnsi0
 *    created: 12.10.2021 00:14:02
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
        vector<pair<int, int>> p(n);
        vector<int> a(n, 0), b(n, 0);
        for (int i = 0; i < n; ++i) {
            cin >> p[i].first >> p[i].second;
            p[i].first--, p[i].second--;
            a[p[i].first]++, b[p[i].second]++;
        }
        long long res = (long long)n * (n - 1) * (n - 2) / 6;
        for (int i = 0; i < n; ++i) {
            res -= (long long)(a[p[i].first] - 1) * (b[p[i].second] - 1);
        }
        cout << res << "\n";
    }
}
