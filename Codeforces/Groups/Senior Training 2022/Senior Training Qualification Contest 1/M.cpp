/**
 *    author:  MaGnsi0
 *    created: 11.03.2022 19:46:32
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("pair.in", "r", stdin);
    int T;
    cin >> T;
    while (T--) {
        long long k;
        string a;
        cin >> a >> k;
        long long ans = 0;
        for (int i = 0; i < (int)a.size(); ++i) {
            ans = (10 * ans + a[i] - '0') % k;
        }
        cout << (ans ? "NO" : "YES") << "\n";
    }
}
