/**
 *    author:  MaGnsi0
 *    created: 13.11.2021 22:10:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int a, b, q;
        cin >> a >> b >> q;
        int n = a * b;
        vector<long long> p(n + 1, 0);
        for (int i = 1; i <= n; ++i) {
            p[i] += ((i % a) % b != (i % b) % a);
            p[i] += p[i - 1];
        }
        auto f = [=](long long l) {
            long long cnt = l / n, r = l % n;
            return p[n] * cnt + p[r];
        };
        while (q--) {
            long long l, r;
            cin >> l >> r;
            cout << f(r) - f(l - 1) << " ";
        }
        cout << "\n";
    }
}
