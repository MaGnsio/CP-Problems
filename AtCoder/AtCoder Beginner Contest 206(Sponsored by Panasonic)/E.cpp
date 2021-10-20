/**
 *    author:  MaGnsi0
 *    created: 15/07/2021 21:06:51
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long l, r, res = 0;
    cin >> l >> r;
    vector<long long> cnt(r + 1, 0);
    for (long long i = 2; i <= r; ++i) {
        if (cnt[i]) {
            continue;
        }
        for (long long j = i; j <= r; j += i) {
            cnt[j]++;
        }
        //we only need numbers that have one prime divisor i.
        for (long long j = i * i; j <= r; j += i * i) {
            cnt[j] = -1e9;
        }
    }
    for (long long i = 2; i <= r; ++i) {
        if (cnt[i] < 0) {
            continue;
        }
        long long c = (r / i) - ((l - 1) / i);
        if (cnt[i] & 1) {
            res += c * (c - 1) / 2;
        } else {
            res -= c * (c - 1) / 2;
        }
    }
    for (long long i = max(2LL, l); i <= r; ++i) {
        res -= r / i - 1;
    }
    cout << 2 * res;
}
