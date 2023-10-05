/**
 *    author:  MaGnsi0
 *    created: 30/08/2021 23:58:41
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        long long n, cnt = 0;
        cin >> n;
        for (long long i = 3; (i * i + 1) / 2 <= n; i += 2) {
            cnt++;
        }
        cout << cnt << "\n";
    }
}
