/**
 *    author:  MaGnsi0
 *    created: 06.07.2022 19:04:45
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, s;
        cin >> n >> s;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int maxs = 0;
        for (int i = 0; i < n; ++i) {
            if (b[i] != -1) {
                maxs = max(maxs, a[i] - b[i]);
            }
        }
        if (s < maxs) {
            cout << 0 << "\n";
            continue;
        }
        vector<int> remaining(n, 1);
        for (int i = 0; i < n; ++i) {
            if (b[i] != -1) {
                remaining[b[i] - 1] = 0;
            }
        }
        for (int i = 1; i < n; ++i) {
            remaining[i] += remaining[i - 1];
        }
        vector<int> lengths;
        for (int i = 0; i < n; ++i) {
            if (b[i] == -1) {
                lengths.push_back(remaining[n - 1] - (a[i] - s - 2 >= 0 ? remaining[a[i] - s - 2] : 0));
            }
        }
        sort(lengths.begin(), lengths.end());
        int64_t ans = 1;
        for (int i = 0; i < (int)lengths.size(); ++i) {
            ans *= int64_t(lengths[i] - i);
            ans %= MOD;
        }
        cout << ans << "\n";
    }
}
