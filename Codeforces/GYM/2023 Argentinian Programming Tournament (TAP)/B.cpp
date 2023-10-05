/**
 *    author:  MaGnsi0
 *    created: 21.09.2023 10:44:41
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (j + 1 < n && a[i][j] == 'N' && a[i][j + 1] == 'N') {
                ans++, j++;
            }
        }
    }
    cout << ans;
}
