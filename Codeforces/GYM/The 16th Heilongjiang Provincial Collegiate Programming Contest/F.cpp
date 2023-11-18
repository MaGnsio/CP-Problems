/**
 *    author:  MaGnsi0
 *    created: 11.10.2023 20:57:52
**/
#include <bits/stdc++.h>

using namespace std;

int64_t power(int64_t b, int64_t p) {
    int64_t res = 1;
    while (p) {
        if (p & 1) { res *= b; }
        b *= b;
        p /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N; cin >> N;
    vector<int> P(N + 1, 0), L(N + 1), CL(N + 1, 0), F(N + 1, 0);
    P[1] = CL[1] = 1;
    iota(L.begin(), L.end(), 0);
    for (int i = 2; i <= N; ++i) {
        if (P[i]) { continue; }
        for (int j = i; j <= N; j += i) {
            L[j] = min(L[j], i), P[j]++;
        }
    }
    for (int i = 2; i <= N; ++i) {
        int x = i;
        while (x % L[i] == 0) {
            x /= L[i];
            CL[i]++;
        }
    }
    for (int i = 1; i <= N; ++i) {
        if (P[i] == 1 && CL[i] == 1) {
            F[i] = 1;
        } else if (P[i] == 1) {
            F[i] = L[i] * F[i / (L[i] * L[i])];
        } else {
            int64_t x = power(L[i], CL[i]);
            F[i] = 1LL * F[x] * i / x;
        }
    }
    int64_t ans = 0;
    for (int i = 1; i <= N; ++i) {
        ans += 1LL * F[i];
    }
    cout << ans;
}
