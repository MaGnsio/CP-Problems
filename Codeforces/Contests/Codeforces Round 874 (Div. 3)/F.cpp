/**
 *    author:  MaGnsi0
 *    created: 19.05.2023 18:22:30
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int64_t power(int64_t b, int64_t p) {
    int64_t ans = 1;
    while (p) {
        if (p & 1) { ans = ans * b % MOD; }
        b = b * b % MOD;
        p /= 2;
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        map<int, int64_t> mp;
        for (int i = 0; i < n; ++i) {
            mp[a[i]]++;
        }
        sort(a.begin(), a.end());
        a.resize(unique(a.begin(), a.end()) - a.begin());
        n = (int)a.size();
        int64_t ans = 0, val = 1, l = 0;
        for (int i = 0; i < n; ++i) {
            val *= mp[a[i]];
            val %= MOD;
            while (a[i] - a[l] >= k) {
                val *= power(mp[a[l]], MOD - 2);
                val %= MOD;
                l++;
            }
            if (i - l + 1 == k) {
                ans += val;
                ans %= MOD;
            }
        }
        cout << ans << "\n";
    }
}
