/**
 *    author:  MaGnsi0
 *    created: 12.12.2022 19:02:37
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    vector<int> F(N);
    iota(F.begin(), F.end(), 0);
    for (int i = 2; i < N; ++i) {
        if (F[i] == i) {
            for (int j = 2 * i; j < N; j += i) {
                F[j] = min(F[j], i);
            }
        }
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        if (__gcd(x, y) > 1) {
            cout << 0 << "\n";
        } else if (x + 1 == y) {
            cout << -1 << "\n";
        } else {
            int d = y - x, ans = d;
            vector<int> f;
            while (d > 1) {
                f.push_back(F[d]);
                d /= F[d];
            }
            for (auto& z : f) {
                ans = min(ans, z - x % z);
            }
            cout << ans << "\n";
        }
    }
}
