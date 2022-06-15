/**
 *    author:  MaGnsi0
 *    created: 11.05.2022 15:58:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        int x = *min_element(a.begin(), a.end()), ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += (a[i] - x);
        }
        cout << ans << "\n";
    }
}