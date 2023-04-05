/**
 *    author:  MaGnsi0
 *    created: 19.12.2022 13:56:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s, t;
    cin >> s >> t;
    vector<vector<int>> a(26);
    for (int i = 0; i < (int)s.size(); ++i) {
        a[s[i] - 'a'].push_back(i);
    }
    int ans = 1, lower = -1;
    for (int i = 0; i < (int)t.size(); ++i) {
        auto it = upper_bound(a[t[i] - 'a'].begin(), a[t[i] - 'a'].end(), lower);
        if (it == a[t[i] - 'a'].end()) {
            lower = -1;
            ans++;
            i--;
            continue;
        }
        lower = *it;
    }
    cout << ans;
}
