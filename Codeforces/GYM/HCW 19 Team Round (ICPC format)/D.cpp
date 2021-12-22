/**
 *    author:  MaGnsi0
 *    created: 05.11.2021 19:03:42
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    long long x, y, r;
    int n;
    cin >> x >> y >> r >> n, r *= r;
    vector<long long> X(n), Y(n);
    for (int i = 0; i < n; ++i) {
        cin >> X[i] >> Y[i];
    }
    long long res = 0;
    set<pair<long long, long long>> s;
    for (int i = 0; i < n; ++i) {
        long long dx = (X[i] - x) * (X[i] - x);
        long long dy = (Y[i] - y) * (Y[i] - y);
        long long d = dx + dy;
        long long g = gcd(X[i] - x, Y[i] - y);
        X[i] = (X[i] - x) / g;
        Y[i] = (Y[i] - y) / g;
        if (d <= r && s.count({X[i], Y[i]}) == 0) {
            s.insert({X[i], Y[i]});
            res++;
        }
    }
    cout << res;
}
