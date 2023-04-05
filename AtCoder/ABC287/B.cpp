/**
 *    author:  MaGnsi0
 *    created: 01.02.2023 21:39:44
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    set<string> b;
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        b.insert(s);
    }
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += b.count(a[i].substr(3));
    }
    cout << ans;
}
