/**
 *    author:  MaGnsi0
 *    created: 18.06.2022 14:46:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> X(n);
    for (int i = 0; i < n; ++i) {
        cin >> X[i];
        X[i]--;
    }
    vector<int64_t> C(n);
    for (int i = 0; i < n; ++i) {
        cin >> C[i];
    }
    vector<int64_t> F(n);
    for (int i = 0; i < n; ++i) {
        F[X[i]] += C[i];
    }
    set<pair<int64_t, int>> S;
    for (int i = 0; i < n; ++i) {
        S.emplace(F[i], i);
    }
    vector<bool> V(n, false);
    int64_t ans = 0;
    while (!S.empty()) {
        auto x = S.begin();
        ans += x -> first;
        if (!V[X[x -> second]]) {
            S.erase(S.find({F[X[x -> second]], X[x -> second]}));
            F[X[x -> second]] -= C[x -> second];
            S.emplace(F[X[x -> second]], X[x -> second]);
        }
        V[x -> second] = true;
        S.erase(x);
    }
    cout << ans;
}
