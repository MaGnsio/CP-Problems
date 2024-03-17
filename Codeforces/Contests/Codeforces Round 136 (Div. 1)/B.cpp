/**
 *    author:  MaGnsi0
 *    created: 08.01.2024 10:58:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int block_size = sqrt(m) + 1;
    vector<int> low(m), high(m), I(m);
    for (int i = 0; i < m; ++i) {
        cin >> low[i] >> high[i];
        low[i]--, high[i]--;
    }
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
            return make_pair(low[i] / block_size, high[i]) < make_pair(low[j] / block_size, high[j]);
        });
    int good = 0;
    vector<int> F(n + 1);
    function<void(int)> add = [&](int x) {
        if (x < 0 || x >= n || a[x] > n) { return; }
        good -= F[a[x]] == a[x], F[a[x]]++, good += F[a[x]] == a[x];
    };
    function<void(int)> remove = [&](int x) {
        if (x < 0 || x >= n || a[x] > n) { return; }
        good -= F[a[x]] == a[x], F[a[x]]--, good += F[a[x]] == a[x];
    };
    int L = -1, R = -1;
    vector<int> ans(m);
    for (int i : I) {
        while (L > low[i]) { L--; add(L); }
        while (R < high[i]) { R++; add(R); }
        while (L < low[i]) { remove(L); L++; }
        while (R > high[i]) { remove(R); R--; }
        ans[i] = good;
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }
}
