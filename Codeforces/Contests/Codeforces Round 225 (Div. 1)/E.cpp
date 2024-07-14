/**
 *    author:  MaGnsi0
 *    created: 15.07.2024 01:07:21
**/
#include <bits/stdc++.h>

using namespace std;

const int M = 24;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> cnt(1 << M);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int m = 0;
        for (char c : s) {
            m |= 1 << (c - 'a');
        }
        m ^= (1 << M) - 1;
        cnt[m]++;
    }
    for (int c = 0; c < 24; ++c) {
        for (int mask = 0; mask < (1 << M); ++mask) {
            if (!(mask >> c & 1)) {
                cnt[mask] += cnt[mask | (1 << c)];
            }
        }
    }
    int ans = 0;
    for (int mask = 0; mask < (1 << M); ++mask) {
        ans ^= (n - cnt[mask]) * (n - cnt[mask]);
    }
    cout << ans;
}
