/**
 *    author:  MaGnsi0
 *    created: 18.11.2023 14:06:34
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i = 0; i < m; ++i) {
        cin >> a[i]; a[i]--;
    }
    vector<int> b(n, 0);
    set<pair<int, int>> s;
    for (int i = 0; i < n; ++i) {
        s.emplace(0, i);
    }
    for (int i = 0; i < m; ++i) {
        s.erase(make_pair(b[a[i]], a[i]));
        b[a[i]]--;
        s.emplace(b[a[i]], a[i]);
        cout << s.begin() -> second + 1 << "\n";
    }
}
