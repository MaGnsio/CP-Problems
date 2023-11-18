/**
 *    author:  MaGnsi0
 *    created: 18.11.2023 14:18:23
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int Q; cin >> Q;
    vector<set<int>> C(n);
    for (int i = 0; i < n; ++i) {
        int c; cin >> c;
        C[i].insert(c);
    }
    while (Q--) {
        int a; cin >> a; a--;
        int b; cin >> b; b--;
        if (C[a].size() > C[b].size()) {
            C[a].swap(C[b]);
        }
        for (int c : C[a]) {
            C[b].insert(c);
        }
        C[a].clear();
        cout << C[b].size() << "\n";
    }
}
