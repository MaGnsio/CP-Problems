/**
 *    author:  MaGnsi0
 *    created: 22.09.2023 21:52:36
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("B.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n, m, a, b;
        cin >> n >> m >> a >> b;
        cout << "Case #" << t << ": ";
        cout << (n > m ? "YES" : "NO") << "\n";
    }
}
