/**
 *    author:  MaGnsi0
 *    created: 19.09.2022 16:32:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int64_t> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        vector<int64_t> ans(k);
        for (int i = 0; i < n; ++i) {
            ans[i % k] = max(ans[i % k], a[i]);
        }
        cout << accumulate(ans.begin(), ans.end(), int64_t(0)) << "\n";
    }
}
