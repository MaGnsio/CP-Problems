/**
 *    author:  MaGnsi0
 *    created: 17.10.2025 18:08:56
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        int k; cin >> k;
        vector<int> a(n), lo(n, -1);
        for (int i = 0; i < n; ++i) {
            cin >> a[i]; a[i]--; lo[a[i]] = i;
        }
        set<tuple<int, int>> S; 
        for (int i = 0; i < n; ++i) {
            S.emplace(lo[i], i);
        }
        for (int i = 0; i < k; ++i) {
            int x = get<1>(*S.begin());
            S.erase(S.begin());
            lo[x] = n + i;
            S.emplace(lo[x], x);
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
}
