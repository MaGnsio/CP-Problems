/**
 *    author:  MaGnsi0
 *    created: 23.11.2024 17:23:48
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 2e5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int64_t> primes;
    vector<bool> is_prime(N, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (!is_prime[i]) { continue; }
        primes.push_back(i);
        for (int j = 2 * i; j < N; j += i) {
            is_prime[j] = false;
        }
    }
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int m; cin >> m;
        vector<int> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());
        vector<int> ans(n, -1);
        for (int i = 0; i < n; ++i) {
            int x = i + 1, primes = 0;
            for (int j = 2; j * j <= x; ++j) {
                while (x % j == 0) { x /= j; primes++; }
            }
            primes += x != 1;
            if (primes >= m) { continue; }
            ans[i] = a[primes];
        }
        bool ok = count(ans.begin(), ans.end(), -1) == 0;
        if (!ok) {
            cout << -1 << "\n";
            continue;
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
}

