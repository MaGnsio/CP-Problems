/**
 *    author:  MaGnsi0
 *    created: 06.03.2023 15:53:26
**/
#include <bits/stdc++.h>

using namespace std;

int solve(int n, int m, vector<int> a, vector<int> b, int k, int p, vector<int> c, vector<int> d) {
    int ans = 0;
    vector<bool> in_c(n + m + 1, false);
    for (int i = 0; i < k; ++i) {
        in_c[c[i]] = true;
    }
    vector<int> from_a_to_b, new_a;
    for (int i = 0, j = 0; i < n; ++i) {
        if (j < k && a[i] == c[j]) {
            new_a.push_back(a[i]);
            j++;
        } else {
            if (in_c[a[i]]) {
                from_a_to_b.push_back(a[i]);
            } else {
                ans++;
            }
        }
    }
    ans += (int)from_a_to_b.size();
    a = new_a;
    reverse(b.begin(), b.end());
    reverse(d.begin(), d.end());
    map<int, int> mp;
    for (int i = 0; i < p; ++i) {
        mp[d[i]] = i;
    }
    for (auto& x : from_a_to_b) {
        if (mp.count(x) == 0) {
            mp[x] = 1'000'000;
        }
    }
    sort(from_a_to_b.begin(), from_a_to_b.end(), [&](int x, int y) {
            return mp[x] < mp[y];
        });
    for (auto& x : from_a_to_b) {
        b.push_back(x);
    }
    m = (int)b.size();
    for (int i = 0, j = 0; i < m; ++i) {
        if (j < p && b[i] == d[j]) {
            j++;
        } else {
            if (mp.count(b[i]) == 0 || mp[b[i]] == 1'000'000) {
                ans++;
            } else {
                ans += 2;
            }
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }
    int k, p;
    cin >> k >> p;
    vector<int> c(k), d(p);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    for (int i = 0; i < p; ++i) {
        cin >> d[i];
    }
    int ans = solve(n, m, a, b, k, p, c, d);
    swap(n, m);
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    swap(a, b);
    swap(k, p);
    reverse(c.begin(), c.end());
    reverse(d.begin(), d.end());
    swap(c, d);
    ans = min(ans, solve(n, m, a, b, k, p, c, d));
    cout << ans;
}
