/**
 *    author:  MaGnsi0
 *    created: 02/09/2021 21:23:07
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N = 1e7, a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<long long> f(N, 0);
    for (int i = a; i <= b; ++i) {
        f[b + i]++;
        f[c + i + 1]--;
    }
    for (int t = 0; t < 2; ++t) {
        for (int i = 1; i < N; ++i) {
            f[i] += f[i - 1];
        }
    }
    long long cnt = 0;
    for (int i = c; i <= d; ++i) {
        cnt += f[N - 1] - f[i];
    }
    cout << cnt;
}
