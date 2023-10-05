/**
 *    author:  MaGnsi0
 *    created: 21.02.2023 19:10:12
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
        vector<pair<int, int>> a;
        for (int i = 2; i * i <= n; ++i) {
            if (n % i == 0) {
                int cnt = 0;
                while (n % i == 0) {
                    n /= i;
                    cnt++;
                }
                a.emplace_back(cnt, i);
            }
        }
        if (n > 1) {
            a.emplace_back(1, n);
        }
        sort(a.begin(), a.end());
        int64_t ans = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            int64_t add = a[i].first, x = a[i].first;
            for (int j = i; j < (int)a.size(); ++j) {
                a[j].first -= x;
                add *= a[j].second;
            }
            ans += add;
        }
        cout << ans << "\n";
    }
}
