/**
 *    author:  MaGnsi0
 *    created: 17/08/2021 20:21:13
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

vector<bool> is_prime(N, true);
vector<int> f(N, 0), cnt(N, 1), p(N, 0);

void init() {
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i < N; ++i) {
        if (is_prime[i]) {
            for (int j = 2 * i; j < N; j += i) {
                int x = j, k = 0;
                while (x % i == 0) {
                    x /= i;
                    k++;
                }
                p[j]++;
                cnt[j] *= (k + 1);
                is_prime[j] = false;
            }
        }
    }
    cnt[0] = cnt[1] = 0;
    for (int i = 2; i < N; ++i) {
        cnt[i]--;
        cnt[i] -= (!is_prime[i]);
    }
    for (int i = 1; i < N; ++i) {
        if (cnt[i] < 2 || (cnt[i] == 2 && p[i] == 2)) {
            f[i] = 1;
        }
    }
    for (int i = 1; i < N; ++i) {
        f[i] += f[i - 1];
    }
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    init();
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        cout << "Case " << t << ": ";
        cout << f[n] / __gcd(n, f[n]) << "/" << n / __gcd(n, f[n]) << "\n";
    }
}
