/**
 *    author:  MaGnsi0
 *    created: 25.08.2024 17:50:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<pair<int, int>> F(26, {0, 0});
        for (int i = 0; i < 26; ++i) {
            F[i].second = i;
        }
        for (int i = 0; i < n; ++i) {
            F[s[i] - 'a'].first++;
        }
        sort(F.rbegin(), F.rend());
        string ans = "";
        while (true) {
            sort(F.rbegin(), F.rend());
            if (F[0].first == 0) { break; }
            if (ans.back() == char('a' + F[0].second)) {
                if (F[1].first == 0) {
                    ans += char('a' + F[0].second); F[0].first--;
                } else {
                    ans += char('a' + F[1].second); F[1].first--;
                }
            } else {
                ans += char('a' + F[0].second); F[0].first--;
            }
        }
        cout << ans << "\n";
    }
}
