/**
 *    author:  MaGnsi0
 *    created: 22.09.2023 22:50:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("A1.in", "r", stdin);
    freopen("A1.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int S, D, K;
        cin >> S >> D >> K;
        int buns = 2 * (S + D);
        int patties = S + 2 * D;
        cout << "Case #" << t << ": ";
        cout << (buns >= K + 1 && patties >= K ? "YES" : "NO") << "\n";
    }
}
