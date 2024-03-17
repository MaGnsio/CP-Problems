/**
 *    author:  MaGnsi0
 *    created: 09.12.2023 14:29:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int64_t a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    if (a * c * e != b * d * f) {
        cout << -1;
    } else {
        int64_t BC = b * c;
        int64_t AB = a * BC / b;
        int64_t CA = d * BC / c;
        int64_t X[3] = {BC, AB, CA};
        sort(X, X + 3);
        cout << (X[0] + X[1] > X[2] ? 1 : -1);
    }
}
