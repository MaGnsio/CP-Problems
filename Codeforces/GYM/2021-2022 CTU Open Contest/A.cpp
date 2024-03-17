/**
 *    author:  MaGnsi0
 *    created: 31.01.2024 20:57:20
**/
#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n) {
    for (int i = 2; i < n; ++i) {
        if (n % i == 0) { return false; }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    vector<int> primes;
    for (int i = n; i >= 2; --i) {
        if (is_prime(i)) {
            primes.push_back(i);
        }
    }
    int m = (int)primes.size();
    vector<int64_t> ans(m); ans[0] = 1;
    for (int i = 1; i < m; ++i) {
        for (int j = 0; j < i; ++j) {
            if (primes[j] - primes[i] <= 14) {
                ans[i] += ans[j];
            }
        }
    }
    cout << ans[m - 1];
}
