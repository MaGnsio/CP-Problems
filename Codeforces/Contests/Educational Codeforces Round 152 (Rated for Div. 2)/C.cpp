/**
 *    author:  MaGnsi0
 *    created: 27.07.2023 17:50:00
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n;
        cin >> m;
        string s;
        cin >> s;
        vector<int> next1(n, n), prev0(n, -1);
        next1[n - 1] = (s[n - 1] == '1' ? n - 1 : n);
        for (int i = n - 2; i >= 0; --i) {
            next1[i] = (s[i] == '1' ? i : next1[i + 1]);
        }
        prev0[0] = (s[0] == '0' ? 0 : -1);
        for (int i = 1; i < n; ++i) {
            prev0[i] = (s[i] == '0' ? i : prev0[i - 1]);
        }
        set<pair<int, int>> ans;
        for (int i = 0; i < m; ++i) {
            int L, R;
            cin >> L >> R;
            L = next1[L - 1];
            R = prev0[R - 1];
            if (L >= R) {
                ans.emplace(-1, -1);
            } else {
                ans.emplace(L, R);
            }
        }
        cout << (int)ans.size() << "\n";
    }
}
