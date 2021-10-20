/**
 *    author:  MaGnsi0
 *    created: 14/08/2021 22:05:55
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long p1 = 1e9 + 7, b1 = 393241;
    vector<long long> power1(2500, 1);
    for (int i = 1; i < 2500; ++i) {
        power1[i] = (power1[i - 1] * b1) % p1;
    }
    long long p2 = 1e9 + 9, b2 = 786433;
    vector<long long> power2(2500, 1);
    for (int i = 1; i < 2500; ++i) {
        power2[i] = (power2[i - 1] * b2) % p2;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> v(n);
        map<pair<int, int>, int> mp;
        for (int i = 0; i < n; ++i) {
            int x, y;
            cin >> x >> y;
            if (x > y) {
                swap(x, y);
            }
            if (!mp.count({x, y})) {
                mp[{x, y}] = i + 1;
            }
            v[i] = mp[{x, y}];
        }
        vector<long long> h1(n), h2(n);
        for (int i = 0; i < n; ++i) {
            h1[i] = power1[v[i]];
            h2[i] = power2[v[i]];
        }
        for (int i = 1; i < n; ++i) {
            h1[i] = (h1[i] + h1[i - 1]) % p1;
            h2[i] = (h2[i] + h2[i - 1]) % p2;
        }
        long long ans = 0;
        for (int i = 1; i < n; ++i) {
            map<pair<long long, long long>, long long> cnt;
            for (int j = n - 1; j - i >= -1; --j) {
                long long a = (h1[j] - (j - i == -1 ? 0LL : h1[j - i]) + p1) % p1;
                long long b = (h2[j] - (j - i == -1 ? 0LL : h2[j - i]) + p2) % p2;
                cnt[{a, b}]++;
            }
            for (auto& [x, y] : cnt) {
                ans += y * (y - 1) / 2;
            }
        }
        cout << ans << "\n";
    }
}
