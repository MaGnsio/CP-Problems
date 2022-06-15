/**
 *    author:  MaGnsi0
 *    created: 02.04.2022 01:31:07
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        int ans = 0;
        for (int i = 0, cur = 1; i < n; ++i) {
            if (a[i] >= cur) {
                ans++;
                cur++;
            }
        }
        cout << "Case #" << t << ": " << ans << "\n";
    }
}
