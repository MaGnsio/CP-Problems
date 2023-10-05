/**
 *    author:  MaGnsi0
 *    created: 06.09.2023 00:27:18
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; ++i) {
        int ans = 0, j = i, turn = 1;
        while (j <= n) {
            int k = min(j + 3 * turn, n + 1);
            int add = a[k - 1] - a[j - 1];
            ans += (add > 0) * add;
            j = k, turn++;
        }
        cout << ans << "\n";
    }
}
