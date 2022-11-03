/**
 *    author:  MaGnsi0
 *    created: 31.07.2022 16:02:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> b;
        b.push_back(a[0] - 1 + n - a[m - 1]);
        for (int i = 1; i < m; ++i) {
            b.push_back(a[i] - a[i - 1] - 1);
        }
        sort(b.begin(), b.end(), greater<int>());
        int ans = n, cur_day = 0;
        for (int i = 0; i < m; ++i) {
            b[i] = max(b[i] - 2 * cur_day, 0);
            if (b[i] == 0) {
                continue;
            }
            if (b[i] <= 2) {
                ans--;
                cur_day++;
            } else {
                ans -= b[i] - 1;
                cur_day += 2;
            }
        }
        cout << ans << "\n";
    }
}
