/**
 *    author:  MaGnsi0
 *    created: 06.05.2023 19:13:48
**/
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

const int64_t N = 2e7 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int M = 0;
    vector<int64_t> GPF(N), I(N);
    iota(GPF.begin(), GPF.end(), 0);
    GPF[0] = GPF[1] = 0;
    for (int i = 2; i < N; ++i) {
        if (GPF[i] == i) {
            for (int j = 2 * i; j < N; j += i) {
                GPF[j] = i;
            }
            I[i] = ++M;
        }
    }
    int n, d;
    cin >> n >> d;
    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int64_t x = 0, y = 0;
    for (int i = 0; i < d; ++i) {
        int j = i % n;
        if (I[GPF[a[j]]] & 1) {
            x += GPF[a[j]];
        } else {
            y += GPF[a[j]];
        }
        if (GPF[a[j]]) {
            a[j] /= GPF[a[j]];
        }
        cout << (x >= y ? "R" : "B") << "\n";
    }
}
