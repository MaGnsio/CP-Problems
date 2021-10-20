/**
 *    author:  MaGnsi0
 *    created: 03/06/2021 20:26:37
**/
#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
    if (n < 2) {
        return false;
    }
    if (n < 4) {
        return true;
    }
    if (n % 2 == 0 || n % 3 == 0) {
        return false;
    }
    for (long long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    vector<int> prime;
    for (int i = 2; i < 48; ++i) {
        if (is_prime(i)) {
            prime.push_back(i);
        }
    }
    int T;
    cin >> T;
    while (T--) {
        long long N, k = 1;
        cin >> N;
        int cnt = 0;
        for (auto& x : prime) {
            k *= x;
            if (k <= N) {
                cnt++;
            }
        }
        cout << cnt << "\n";
    }
}
