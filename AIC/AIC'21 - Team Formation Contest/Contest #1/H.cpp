/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:45
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N = 1e6 + 6;
    vector<bool> is_prime(N, true);
    vector<int> f(N, 0);
    f[1]++;
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) {
            f[i]++;
            for (int j = 2 * i; j < N; j += i) {
                is_prime[j] = false;
            }
        }
    }
    for (int i = 1; i < N; ++i) {
        f[i] += f[i - 1];
    }
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        cout << "Case #" << t << ": " << f[n] << "\n";
    }
}
