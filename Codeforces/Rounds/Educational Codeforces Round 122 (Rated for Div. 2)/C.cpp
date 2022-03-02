/**
 *    author:  MaGnsi0
 *    created: 31.01.2022 23:26:30
**/
#include <bits/stdc++.h>

using namespace std;

bool check(long long hc, long long dc, long long hm, long long dm) {
    long long x = (hm + dc - 1) / dc;
    long long y = (hc + dm - 1) / dm;
    return x <= y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long a[7]; //hc, dc, hm, dm, k, w, a
        for (int i = 0; i < 7; ++i) {
            cin >> a[i];
        }
        bool ok = false;
        for (int i = 0; i <= a[4]; ++i) {
            long long hc = a[0] + i * a[6];
            long long dc = a[1] + (a[4] - i) * a[5];
            ok |= check(hc, dc, a[2], a[3]);
            if (ok) {
                break;
            }
        }
        cout << (ok ? "YES" : "NO") << "\n";
    }
}
