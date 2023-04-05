/**
 *    author:  MaGnsi0
 *    created: 11.02.2023 14:03:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i];
        a[i]--;
    }
    vector<int> p(n);
    iota(p.begin(), p.end(), 0);
    function<int(int)> find = [&](int x) {
        return (p[x] == x ? x : find(p[x]));
    };
    function<void(int, int)> unite = [&](int x, int y) {
        x = find(x), y = find(y);
        if (x < y) { swap(x, y); }
        p[x] = y;
    };
    for (int i = 0; i < m; ++i) {
        unite(a[i], a[i] + 1);
    }
    map<int, vector<int>> mp;
    for (int i = n - 1; i >= 0; --i) {
        mp[find(i)].push_back(i);
    }
    for (auto& [_, b] : mp) {
        for (auto& x : b) {
            cout << x + 1 << " ";
        }
    }
}
