/**
 *    author:  MaGnsi0
 *    created: 19.04.2023 13:00:45
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m;
    string s;
    cin >> s;
    k = (int)s.size();
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> pi(k);
    for (int i = 1; i < k; ++i) {
        int j = pi[i - 1];
        while (j && s[i] != s[j]) { j = pi[j - 1]; }
        pi[i] = j + (s[i] == s[j]);
    }
    int x = pi[k - 1];
    set<int> good;
    while (x) {
        good.insert(x);
        x = pi[x - 1];
    }
    for (int i = 1; i < m; ++i) {
        int j = a[i - 1] + k - 1;
        if (j < a[i]) { continue; }
        int x = j - a[i] + 1;
        if (good.count(x)) { continue; }
        cout << 0;
        return 0;
    }
    vector<int> b(n + 1);
    for (int i = 0; i < m; ++i) {
        b[a[i]]++, b[a[i] + k]--;
    }
    for (int i = 1; i <= n; ++i) {
        b[i] += b[i - 1];
    }
    int64_t ans = 1;
    for (int i = 0; i < n; ++i) {
        if (b[i] == 0) {
            ans *= 26;
            ans %= MOD;
        }
    }
    cout << ans;
}
