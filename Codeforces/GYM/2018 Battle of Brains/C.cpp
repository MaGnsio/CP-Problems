/**
 *    author:  MaGnsi0
 *    created: 17/08/2021 20:14:31
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        double r;
        cin >> r;
        cout << "Case " << t << ": ";
        cout << fixed << setprecision(4) << r * r / 4.0 << "\n";
    }
}
