/**
 *    author:  MaGnsi0
 *    created: 05.10.2024 20:22:50
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<bool> is_prime(N, true), taken(N, false);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (!is_prime[i]) { continue; }
        for (int j = 2 * i; j < N; j += i) {
            is_prime[j] = false;
        }
    }
    vector<int> ans(N);
    for (int i = 3; i < N; ++i) {
        if (!is_prime[i]) { continue; }
        if (is_prime[i - 2]) {
            ans[i] += taken[2] == false;
            taken[2] = true;
        }
        if (is_prime[i - 2]) {
            ans[i] += taken[i - 2] == false;
            taken[i - 2] = true;
        }
    }
    for (int i = 1; i < N; ++i) {
        ans[i] += ans[i - 1];
    }
    int T; cin >> T;
    for (int t = 1; t <= T; ++t) {
        cout << "Case #" << t << ": ";
        int n; cin >> n;
        cout << ans[n] << "\n";
    }
}
