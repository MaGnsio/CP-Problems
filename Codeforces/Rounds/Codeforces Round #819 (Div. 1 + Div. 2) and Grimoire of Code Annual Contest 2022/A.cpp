/**
 *    author:  MaGnsi0
 *    created: 06.09.2022 16:34:01
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
        int max1 = a[n - 1], max2 = *max_element(a.begin(), a.end());
        int min1 = a[0], min2 = *min_element(a.begin(), a.end());
        int ans = max({max1 - min1, max1 - min2, max2 - min1}); 
        for (int i = 0; i < n; ++i) {
            ans = max(ans, a[i] - a[(i + 1) % n]);
        }
        cout << ans << "\n";
    }
}
