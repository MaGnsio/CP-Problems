/**
 *    author:  MaGnsi0
 *    created: 16.07.2022 16:33:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int cur_q = 0;
        string ans(n, '1');
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] > cur_q) {
                if (cur_q < q) {
                    cur_q++;
                } else {
                    ans[i] = '0';
                }
            }
        }
        cout << ans << "\n";
    }
}
