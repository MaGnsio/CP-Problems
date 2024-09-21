/**
 *    author:  MaGnsi0
 *    created: 21.09.2024 15:02:27
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int m; cin >> m;
    int p = 0;
    vector<int> ans;
    while (m) {
        for (int i = 0; i < (m % 3); ++i) {
            ans.push_back(p);
        }
        m /= 3; p++;
    }
    int n = (int)ans.size();
    cout << n << "\n";
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
