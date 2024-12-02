/**
 *    author:  MaGnsi0
 *    created: 02.12.2024 21:09:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int64_t ans = 0;
    vector<int64_t> F(5, 0);
    for (int i = 0; i < n; ++i) {
        string s, t = ""; cin >> s;
        for (char c : s) {
            if (c != '.') { t += c; }
        }
        int y = stoi(t); ans += y; F[y % 5]++;
    }
    ans -= F[1]; ans -= 2 * F[2];
    int t = min(F[3], F[4]);
    ans -= 2 * t; F[3] -= t; F[4] -= t;
    ans -= (F[3] / 2); ans -= 2 * (F[4] / 3);
    cout << fixed << setprecision(2) << 1.0 * ans / 100.0;
}
