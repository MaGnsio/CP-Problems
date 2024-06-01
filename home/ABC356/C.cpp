/**
 *    author:  MaGnsi0
 *    created: 01.06.2024 15:05:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<bool> a(m, false);
    vector<vector<int>> b(m);
    for (int i = 0; i < m; ++i) {
        int s; cin >> s;
        for (int j = 0; j < s; ++j) {
            int x; cin >> x; x--;
            b[i].push_back(x);
        }
        char c; cin >> c; a[i] = c == 'o';
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        bool good = true;
        for (int i = 0; i < m; ++i) {
            int count = 0;
            for (int key : b[i]) {
                count += (mask >> key & 1);
            }
            good = good && ((count >= k) == a[i]);
        }
        ans += good;
    }
    cout << ans;
}
