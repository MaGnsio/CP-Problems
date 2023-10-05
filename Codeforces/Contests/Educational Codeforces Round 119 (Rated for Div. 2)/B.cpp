/**
 *    author:  MaGnsi0
 *    created: 13.01.2022 23:38:14
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long h, w;
        cin >> h >> w;
        long long res = 0;
        for (int i = 0; i < 4; ++i) {
            int k;
            cin >> k;
            vector<long long> a(k);
            for (int j = 0; j < k; ++j) {
                cin >> a[j];
            }
            res = max((a[k - 1] - a[0]) * (i < 2 ? w : h), res);
        }
        cout << res << "\n";
    }
}
