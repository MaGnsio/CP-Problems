/**
 *    author:  MaGnsi0
 *    created: 01.02.2023 22:11:11
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m = 1;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        m = max(m, (int)a[i].size() + 1);
    }
    vector<map<pair<int64_t, int64_t>, int>> mp(m);
    function<void(string)> insert = [&](string s) {
        const int64_t p1 = 31, MOD1 = 1e9 + 9;
        const int64_t p2 = 53, MOD2 = 1e9 + 7;
        int64_t hash_value1 = 0, p_pow1 = 1;
        int64_t hash_value2 = 0, p_pow2 = 1;
        for (int i = 0; i < (int)s.size(); ++i) {
            hash_value1 = (hash_value1 + (s[i] - 'a' + 1) * p_pow1) % MOD1;
            p_pow1 = (p_pow1 * p1) % MOD1;
            hash_value2 = (hash_value2 + (s[i] - 'a' + 1) * p_pow2) % MOD2;
            p_pow2 = (p_pow2 * p2) % MOD2;
            mp[i + 1][{hash_value1, hash_value2}]++;
        }
    };
    for (int i = 0; i < n; ++i) {
        insert(a[i]);
    }
    vector<int> ans(n, 0);
    function<void(int)> solve = [&](int j) {
        const int64_t p1 = 31, MOD1 = 1e9 + 9;
        const int64_t p2 = 53, MOD2 = 1e9 + 7;
        int64_t hash_value1 = 0, p_pow1 = 1;
        int64_t hash_value2 = 0, p_pow2 = 1;
        for (int i = 0; i < (int)a[j].size(); ++i) {
            hash_value1 = (hash_value1 + (a[j][i] - 'a' + 1) * p_pow1) % MOD1;
            p_pow1 = (p_pow1 * p1) % MOD1;
            hash_value2 = (hash_value2 + (a[j][i] - 'a' + 1) * p_pow2) % MOD2;
            p_pow2 = (p_pow2 * p2) % MOD2;
            if (mp[i + 1][{hash_value1, hash_value2}] > 1) {
                ans[j] = i + 1;
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        solve(i);
    }
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << "\n";
    }
}
