/**
 *    author:  MaGnsi0
 *    created: 31.03.2023 16:39:55
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            cout << -1 << "\n";
            continue;
        }
        int j = n / 2;
        vector<int> ans;
        while (j) {
            ans.push_back(j & 1 ? 2 : 1);
            j = (j & 1 ? (j - 1) / 2 : j / 2);
        }
        reverse(ans.begin(), ans.end());
        int m = (int)ans.size();
        cout << m << "\n";
        for (int i = 0; i < m; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
