/*
ID: magnsi01
LANG: C++
TASK: gift1
*/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        mp[a[i]] = 0;
    }
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        int c, m;
        cin >> c >> m;
        if (m == 0) {
            continue;
        }
        mp[x] -= m * (c / m);
        for (int i = 0; i < m; ++i) {
            string y;
            cin >> y;
            mp[y] += (c / m);
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i] << " " << mp[a[i]] << "\n";
    }
}
