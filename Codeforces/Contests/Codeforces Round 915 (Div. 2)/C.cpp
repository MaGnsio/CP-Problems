/**
 *    author:  MaGnsi0
 *    created: 18.12.2023 14:22:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> next_greater(n + 1, -1);
        for (int i = n - 1; i >= 0; --i) {
            if (next_greater[i + 1] == -1) {
                next_greater[i] = i;
            } else if (s[next_greater[i + 1]] > s[i]) {
                next_greater[i] = next_greater[i + 1];
            } else {
                next_greater[i] = i;
            }
        }
        string t = "", x = "";
        vector<int> mls;
        for (int j = next_greater[0]; j != -1; j = next_greater[j + 1]) {
            t += s[j]; x += s[j];
            mls.push_back(j);
        }
        int m = (int)t.size();
        sort(x.begin(), x.end());
        for (int i = 0; i < (int)t.size(); ++i) {
            s[mls[i]] = x[i];
        }
        if (is_sorted(s.begin(), s.end())) {
            int ans = m;
            for (int i = 0; i < m; ++i) {
                if (t[i] != t[0]) { break; }
                ans--;
            }
            cout << ans << "\n";
        } else {
            cout << -1 << "\n";
        }
    }
}
