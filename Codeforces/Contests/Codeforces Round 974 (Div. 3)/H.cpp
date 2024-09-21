/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 17:58:54
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 5;
const array<int64_t, 2> B = {31, 53};
const array<int64_t, 2> MOD = {int64_t(1e9 + 7), int64_t(1e9 + 9)};
 
vector<array<int64_t, 2>> P(N);
 
struct H {
    array<int64_t, 2> hash;
    H() { hash[0] = hash[1] = 0; }
};
 
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    P[0][0] = P[0][1] = 1;
    for (int i = 1; i < N; ++i) {
        for (int j = 0; j < 2; ++j) {
            P[i][j] = P[i - 1][j] * B[j] % MOD[j];
        }
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int Q; cin >> Q;
        map<int, int> mp;
        vector<H> pre(n);
        for (int i = 0; i < n; ++i) {
            int x; cin >> x; x--;
            mp[x]++; mp[x] %= 2;
            pre[i] = (i ? pre[i - 1] : H());
            for (int j = 0; j < 2; ++j) {
                pre[i].hash[j] += (mp[x] ? 1 : -1) * P[x][j];
                pre[i].hash[j] += MOD[j];
                pre[i].hash[j] %= MOD[j];
            }
        }
        while (Q--) {
            int l; cin >> l; l--;
            int r; cin >> r; r--;
            if (l == 0) {
                cout << ((pre[r].hash[0] == 0) && (pre[r].hash[1] == 0) ? "YES" : "NO") << "\n";
            } else {
                cout << (pre[r].hash == pre[l - 1].hash ? "YES" : "NO") << "\n";
            }
        }
    }
}
