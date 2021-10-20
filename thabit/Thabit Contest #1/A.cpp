/**
 *    author:  MaGnsi0
 *    created: 19/06/2021 16:37:56
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    int z = 0, o = 0, ans = 0;
    for (int i = 0; i < n; ++i) {
        z += (v[i] == 0);
        o += (v[i] == 1);
        if (z && o) {
            z = o = 0;
            ans++;
        }
    }
    cout << ans;
}
