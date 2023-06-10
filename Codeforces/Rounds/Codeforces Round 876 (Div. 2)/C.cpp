/**
 *    author:  MaGnsi0
 *    created: 03.06.2023 18:21:25
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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        if (a.back() == 1) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
        int last_zero = -1;
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (ans.size() == n) { break; }
            if (a[i] == 0) {
                ans.push_back(i - last_zero - 1);
                for (int j = last_zero + 1; j < i; ++j) {
                    if (ans.size() == n) { break; }
                    ans.push_back(0);
                }
                last_zero = i;
            }
        }
        reverse(ans.begin(), ans.end());
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}
