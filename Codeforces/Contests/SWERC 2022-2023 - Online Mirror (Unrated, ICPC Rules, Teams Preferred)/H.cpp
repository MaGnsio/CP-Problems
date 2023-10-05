/**
 *    author:  TEAM
 *    created: 26.02.2023 17:22:47
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
        vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }
        int ans = 0;
        for (int i = n - 1, j = n - 1; i >= 0; --i) {
            while (j >= 0 && a[j] != b[i]) {
                ans++;
                j--;
            }
            j--;
        }
        cout << ans << "\n";
    }
}
