/**
 *    author:  MaGnsi0
 *    created: 31.10.2021 16:21:25
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k, k++;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        string res = "";
        for (int i = 0; i + 1 < n; ++i) {
            long long cur = 0;
            for (int j = 0; j < a[i + 1] - a[i]; ++j) {
                cur = cur * 10 + 9;
            }
            if (k <= cur) {
                break;
            } else {
                res += to_string(cur);
                k -= cur;
            }
        }
        string x = to_string(k);
        reverse(x.begin(), x.end());
        res += x;
        reverse(res.begin(), res.end());
        cout << res << "\n";
    }
}
