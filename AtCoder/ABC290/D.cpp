/**
 *    author:  MaGnsi0
 *    created: 19.02.2023 16:19:16
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int64_t N, D, K;
        cin >> N >> D >> K;
        K--;
        int64_t L = N / gcd(N, D);
        int64_t X = K / L;
        int64_t Y = K - X * L;
        cout << (X + Y * D % N) % N << "\n";
    }
}
