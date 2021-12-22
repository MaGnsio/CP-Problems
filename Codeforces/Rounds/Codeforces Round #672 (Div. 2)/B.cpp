/**
 *    author:  MaGnsi0
 *    created: 27.10.2021 01:03:59
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
        vector<int> cnt(34, 0);
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cnt[(int)log2(x)]++;
        }
        long long res = 0;
        for (int i = 0; i < 34; ++i) {
            res += (long long)cnt[i] * (cnt[i] - 1) / 2;
        }
        cout << res << "\n";
    }
}
