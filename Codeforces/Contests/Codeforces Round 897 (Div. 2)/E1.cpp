/**
 *    author:  MaGnsi0
 *    created: 17.09.2023 21:44:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        function<int(int)> ask = [&](int j) {
            cout << "? " << j << endl;
            int x; cin >> x;
            return x;
        };
        int ans = 0;
        for (int i = 1; i + k - 1 <= n; i += k) {
            ans ^= ask(i);
        }
        for (int i = k * (n / k) + 1; i <= n; ++i) {
            ans ^= ask(i - k + 1);
        }
        cout << "! " << ans << endl;
    }
}
