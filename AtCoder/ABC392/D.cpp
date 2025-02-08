/**
 *    author:  MaGnsi0
 *    created: 08.02.2025 14:09:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> a(n);
    vector<map<int, int>> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < a[i]; ++j) {
            int x; cin >> x; b[i][x]++;
        }
    }
    double ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            double prop = 0;
            for (auto [x, y] : b[i]) {
                if (b[j].count(x) == 0) { continue; }
                prop += (1.0 * y / a[i]) * (1.0 * b[j][x] / a[j]);
            }
            ans = max(ans, prop);
        }
    }
    cout << fixed << setprecision(8) << ans;
}
