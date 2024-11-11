/**
 *    author:  MaGnsi0
 *    created: 11.11.2024 18:56:48
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<bool> isprime(N, true);
    isprime[0] = isprime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (!isprime[i]) { continue; }
        for (int j = 2 * i; j < N; j += i) {
            isprime[j] = false;
        }
    }
    int n; cin >> n;
    if (n < 3) {
        cout << -1;
    } else {
        for (int i = n; ; --i) {
            if (isprime[i]) {
                cout << (i / 3) << " " << (i / 3) + (i % 3 > 0) << " " << (i / 3) + (i % 3 > 1);
                return 0;
            }
        }
    }
}
