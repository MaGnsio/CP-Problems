/**
 *    author:  MaGnsi0
 *    created: 17/08/2021 19:24:54
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int d;
        long long x;
        cin >> d >> x;
        cout << "Case " << t << ": ";
        if (!x) {
            cout << "YES " << 0 << "\n";
            continue;
        }
        if ((int)log2(x) > d) {
            cout << "NO\n";
            continue;
        }
        int k = 0;
        while (!(x & (1LL << k))) {
            k++;
        }
        cout << "YES " << d - k + 1 << "\n";
    }
}
