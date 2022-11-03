/**
 *    author:  MaGnsi0
 *    created: 21.06.2022 07:35:19
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int h, ans = a[0];
    cin >> h;
    for (int i = 1; i < n; ++i) {
        if (h % a[i] < h % ans) {
            ans = a[i];
        }
    }
    cout << ans;
}
