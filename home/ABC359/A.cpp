/**
 *    author:  MaGnsi0
 *    created: 22.06.2024 15:00:33
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        ans += s[0] == 'T';
    }
    cout << ans;
}
