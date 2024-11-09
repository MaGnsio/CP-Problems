/**
 *    author:  MaGnsi0
 *    created: 10.11.2024 00:02:56
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> LPF(N);
    iota(LPF.begin(), LPF.end(), 0);
    LPF[0] = LPF[1] = -1;
    for (int i = 2; i < N; ++i) {
        if (LPF[i] != i) { continue; }
        for (int j = i; j < N; j += i) {
            LPF[j] = min(LPF[j], i);
        }
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int primes = 0;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            primes += LPF[a[i]] == a[i];
        }
        sort(a.begin(), a.end());
        if (primes > 1) {
            cout << -1 << "\n";
            continue;
        }
        if (primes == 1 && LPF[a[0]] != a[0]) {
            cout << -1 << "\n";
            continue;
        }
        if (primes == 0 || a[0] == 2) {
            cout << 2 << "\n";
            continue;
        }
        int ans = a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] == 2 * ans) { continue; }
            int x = a[i] - LPF[a[i]];
            if (x == 0) { continue; }
            if (x < 2 * ans) {
                ans = -1;
                break;
            }
        }
        cout << ans << "\n";
    }
}
