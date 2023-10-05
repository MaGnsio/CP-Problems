/**
 *    author:  MaGnsi0
 *    created: 15.09.2023 19:48:10
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        int n = (int)s.size();
        vector<int64_t> cnt(4);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                cnt[0]++;
            } else if (s[i] == '6') {
                cnt[1]++;
            } else if (s[i] == '8') {
                cnt[2]++;
            } else {
                cnt[3]++;
            }
        }
        int64_t ans = (cnt[0] > 0) || (cnt[2] > 0) || (cnt[1] && cnt[3]);
        for (int i = 0; i < n; ++i) {
            if (s[i] == '0') {
                cnt[0]--;
                ans += cnt[1] + cnt[2] + cnt[3];
            } else if (s[i] == '6') {
                cnt[1]--;
                ans += cnt[0] + cnt[1] + cnt[2] + 1;
            } else if (s[i] == '8') {
                cnt[2]--;
                ans += cnt[0] + cnt[1] + cnt[3];
            } else {
                cnt[3]--;
                ans += cnt[0] + cnt[2] + cnt[3] + 1;
            }
        }
        cout << ans << "\n";
    }
}
