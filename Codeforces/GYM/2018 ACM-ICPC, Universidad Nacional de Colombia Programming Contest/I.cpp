/**
 *    author:  MaGnsi0
 *    created: 09.11.2021 13:31:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, M;
    cin >> N >> M;
    while (M--) {
        long long n, k;
        cin >> n >> k;
        k %= N;
        vector<bool> a(N, 0);
        for (int i = 0; i < N; ++i) {
            a[i] = (1LL & (n >> i));
        }
        vector<bool> b(N, 0);
        for (int i = N - k, j = 0; i < N && j < N; ++i, ++j) {
            b[j] = a[i];
        }
        for (int i = 0, j = k; i < N - k && j < N; ++i, ++j) {
            b[j] = a[i];
        }
        long long res = 0;
        for (int i = 0; i < N; ++i) {
            if (b[i]) {
                res |= (1LL << i);
            }
        }
        cout << res << "\n";
    }
}
