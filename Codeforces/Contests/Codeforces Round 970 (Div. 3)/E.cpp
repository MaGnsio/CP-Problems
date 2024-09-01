/**
 *    author:  MaGnsi0
 *    created: 01.09.2024 18:14:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<vector<int>> fe(26, vector<int>(n));
        vector<vector<int>> fo(26, vector<int>(n));
        for (int i = 0; i < n; i += 2) {
            fe[s[i] - 'a'][i]++;
        }
        for (int i = 1; i < n; i += 2) {
            fo[s[i] - 'a'][i]++;
        }
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 26; ++j) {
                fe[j][i] += fe[j][i - 1];
                fo[j][i] += fo[j][i - 1];
            }
        }
        if (n % 2 == 0) {
            int maxe = 0, maxo = 0;
            for (int i = 0; i < 26; ++i) {
                maxe = max(maxe, fe[i][n - 1]);
                maxo = max(maxo, fo[i][n - 1]);
            }
            cout << n - maxe - maxo << "\n";
            continue;
        }
        int ans = n;
        for (int remove = 0; remove < n; ++remove) {
            int maxe = 0, maxo = 0;
            for (int i = 0; i < 26; ++i) {
                maxe = max(maxe, (remove ? fe[i][remove - 1] : 0) + fo[i][n - 1] - fo[i][remove]);
                maxo = max(maxo, (remove ? fo[i][remove - 1] : 0) + fe[i][n - 1] - fe[i][remove]);
            }
            ans = min(ans, n - maxe - maxo);
        }
        cout << ans << "\n";
    }
}
