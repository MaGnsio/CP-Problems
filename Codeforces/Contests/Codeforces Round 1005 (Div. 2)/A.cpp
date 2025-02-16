/**
 *    author:  MaGnsi0
 *    created: 16.02.2025 16:38:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            if (a.empty() || s[i] - '0' != a.back()) {
                a.push_back(s[i] - '0');
            }
        }
        int ans = 0;
        if (a.back() == 1) {
            a.pop_back();
            ans++;
        }
        ans += 2 * ((int)a.size() / 2);
        cout << ans << "\n";
    }
}
