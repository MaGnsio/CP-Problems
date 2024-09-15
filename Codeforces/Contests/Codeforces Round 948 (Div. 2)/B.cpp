/**
 *    author:  MaGnsi0
 *    created: 13.09.2024 20:33:37
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int x; cin >> x;
        vector<int> ans;
        while (x) {
            ans.push_back(x % 2);
            x /= 2;
        }
        ans.push_back(0);
        int n = (int)ans.size();
        for (int i = 0, j; i < n; ++i) {
            if (ans[i] == 0) { continue; }
            for (j = i; j < n; ++j) {
                if (ans[j] == 0) { break; }
            }
            j--;
            if (i == j) { continue; }
            ans[i] = -1;
            for (int k = i + 1; k <= j; ++k) {
                ans[k] = 0;
            }
            ans[j + 1] = 1;
            i = j;
        }
        cout << n << "\n";
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
