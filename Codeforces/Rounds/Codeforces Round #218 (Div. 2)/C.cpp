/**
 *    author:  MaGnsi0
 *    created: 25.10.2021 17:50:50
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    long long A[3], P[3], R[3] = {};
    cin >> A[0] >> A[1] >> A[2];
    cin >> P[0] >> P[1] >> P[2];
    for (auto& c : s) {
        R[0] += (c == 'B');
        R[1] += (c == 'S');
        R[2] += (c == 'C');
    }
    long long p;
    cin >> p;
    auto good = [=](long long amount) {
        long long temp = p;
        for (int i = 0; i < 3; ++i) {
            temp -= max(amount * R[i] - A[i], 0LL) * P[i];
        }
        return (temp >= 0LL);
    };
    long long l = 0, r = 1e15, res = 0;
    while (l <= r) {
        long long mid = (l + r) / 2;
        if (good(mid)) {
            res = mid;
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }
    cout << res;
}
