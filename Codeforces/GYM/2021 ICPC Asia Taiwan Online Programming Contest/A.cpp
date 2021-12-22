/**
 *    author:  MaGnsi0
 *    created: 14.11.2021 16:11:47
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    vector<int> g(n), s(n), p(n);
    for (int i = 0; i < n; ++i) {
        cin >> g[i] >> s[i] >> p[i];
        getline(cin, a[i]);
        a[i].erase(a[i].begin());
    }
    string w = a[0];
    int x = g[0], y = s[0], z = p[0];
    for (int i = 1; i < n; ++i) {
        if ((g[i] > x) || (g[i] == x && s[i] > y) || (g[i] == x && s[i] == y && p[i] > z)) {
            w = a[i], x = g[i], y = s[i], z = p[i];
        }
    }
    cout << w;
}
