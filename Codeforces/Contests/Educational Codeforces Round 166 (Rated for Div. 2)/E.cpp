/**
 *    author:  MaGnsi0
 *    created: 05.06.2024 03:04:47
**/
#include <bits/stdc++.h>

using namespace std;

const int64_t MOD = 998244353;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(m), b(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i]; a[i]--;
    }
    for (int i = 0; i < m; ++i) {
        cin >> b[i]; b[i]--;
    }
    vector<int> C(n, 0), L(n, -1), R(n, -1);
    R[a[0]] = b[0], C[a[0]]++;
    L[b[0]] = a[0], C[b[0]]++;
    for (int i = 1; i < m; ++i) {
        if (C[a[i]] == 0) {
            int x = L[b[i]];
            if (x != -1) { R[x] = a[i]; }
            L[a[i]] = x;
            R[a[i]] = b[i];
            L[b[i]] = a[i];
        } else {
            int x = R[a[i]];
            if (x != -1) { L[x] = b[i]; }
            R[b[i]] = x;
            L[b[i]] = a[i];
            R[a[i]] = b[i];
        }
        C[a[i]]++, C[b[i]]++;
    }
    vector<int> places(n);
    for (int i = 0; i < n; ++i) {
        if (C[i] == 0) { continue; }
        if (L[i] == -1 || R[i] == -1) { places[i]++; }
        if (L[i] != -1) { places[max(i, L[i])]++; }
    }
    for (int i = n - 2; i >= 0; --i) {
        places[i] += places[i + 1];
    }
    int64_t ans = 1, put = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (C[i]) { continue; } 
        ans *= (put + places[i]);
        ans %= MOD;
        put++;
    }
    cout << ans;
}
