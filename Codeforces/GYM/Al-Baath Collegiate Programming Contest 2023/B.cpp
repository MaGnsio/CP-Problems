/**
 *    author:  MaGnsi0
 *    created: 07.07.2023 01:13:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k, m;
        cin >> n >> k >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            int _; cin >> _;
            string s; cin >> s;
            a[i] = 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3, 2));
        }
        sort(a.begin(), a.end());
        int ans = 1;
        for (int i = 1; i < m; ++i) {
            ans += a[i] - a[i - 1] > k;
        }
        cout << ans << "\n";
    }
}
