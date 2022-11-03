/**
 *    author:  MaGnsi0
 *    created: 24.09.2022 19:06:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("A1.in", "r", stdin);
    freopen("A1.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        string s;
        cin >> s;
        int n = (int)s.size();
        vector<vector<int>> F(n, vector<int>(26, 0));
        F[0][s[0] - 'a']++;
        for (int i = 1; i < n; ++i) {
            F[i] = F[i - 1];
            F[i][s[i] - 'a']++;
        }
        int Q, ans = 0;
        cin >> Q;
        for (int q = 0; q < Q; ++q) {
            int L, R;
            cin >> L >> R;
            L--, R--;
            if (R - L + 1 == 1) {
                ans++;
                continue;
            }
            if ((R - L + 1) & 1) {
                int m = (R - L + 1) / 2;
                vector<int> f1 = F[L + m - 1], f2 = F[R];
                if (L) {
                    for (int i = 0; i < 26; ++i) {
                        f1[i] -= F[L - 1][i];
                    }
                }
                for (int i = 0; i < 26; ++i) {
                    f2[i] -= F[L + m][i];
                }
                int cnt1 = 0, cnt2 = 0;
                f1[s[L + m] - 'a']++;
                for (int i = 0; i < 26; ++i) {
                    cnt1 += abs(f1[i] - f2[i]);
                }
                f1[s[L + m] - 'a']--;
                f2[s[L + m] - 'a']++;
                for (int i = 0; i < 26; ++i) {
                    cnt2 += abs(f1[i] - f2[i]);
                }
                ans += (cnt1 == 1 || cnt2 == 1);
            } 
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
