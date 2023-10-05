/**
 *    author:  MaGnsi0
 *    created: 11.12.2022 14:40:08
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
        int ans = *max_element(a.begin(), a.end());
        for (int i = 0; i < n; ++i) {
            if (a[i] == ans) {
                ans = i + 1;
                break;
            }
        }
        cout << ans << "\n";
    }
}
