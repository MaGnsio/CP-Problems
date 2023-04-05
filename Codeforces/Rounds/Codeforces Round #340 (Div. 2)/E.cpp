/**
 *    author:  MaGnsi0
 *    created: 17.02.2023 17:31:35
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        a[i] ^= a[i - 1];
    }
    int b = sqrt(n) + 1;
    vector<int> L(m), R(m), I(m); 
    for (int i = 0; i < m; ++i) {
        cin >> L[i] >> R[i];
        L[i]--, I[i] = i;
    }
    sort(I.begin(), I.end(), [&](int i, int j) {
            return make_pair(L[i] / b, R[i]) < make_pair(L[j] / b, R[j]);
        });
    int64_t res = 0;
    vector<int64_t> F(N, 0);
    function<void(int)> add = [&](int j) {
        if (j < 0 || j > n) { return; }
        int x = a[j];
        if (k) {
            res -= F[x] * F[k ^ x];
            F[x]++;
            res += F[x] * F[k ^ x];
        } else {
            res -= F[x] * (F[x] - 1) / 2;
            F[x]++;
            res += F[x] * (F[x] - 1) / 2;
        }
    };
    function<void(int)> remove = [&](int j) {
        if (j < 0 || j > n) { return; }
        int x = a[j];
        if (k) {
            res -= F[x] * F[k ^ x];
            F[x]--;
            res += F[x] * F[k ^ x];
        } else {
            res -= F[x] * (F[x] - 1) / 2;
            F[x]--;
            res += F[x] * (F[x] - 1) / 2;
        }
    };
    int l = -1, r = -1;
    vector<int64_t> ans(m);
    for (int i = 0; i < m; ++i) {
        int j = I[i];
        while (l > L[j]) {
            l--;
            add(l);
        }
        while (r < R[j]) {
            r++;
            add(r);
        }
        while (l < L[j]) {
            remove(l);
            l++;
        }
        while (r > R[j]) {
            remove(r);
            r--;
        }
        ans[j] = res;
    }
    for (int i = 0; i < m; ++i) {
        cout << ans[i] << "\n";
    }
}
