/**
 *    author:  MaGnsi0
 *    created: 11.02.2023 17:07:03
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
        int cnt = count(a.begin(), a.end(), 2), cur_cnt = 0, ans = -1;
        for (int i = n - 2; i >= 0; --i) {
            cnt -= a[i + 1] == 2;
            cur_cnt += a[i + 1] == 2;
            ans = (cnt == cur_cnt ? i + 1 : ans);
        }
        cout << ans << "\n";
    }
}
