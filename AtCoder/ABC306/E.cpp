/**
 *    author:  MaGnsi0
 *    created: 17.06.2023 15:22:52
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int N, K, Q;
    cin >> N >> K >> Q;
    int64_t ans = 0;
    vector<int64_t> A(N, 0);
    set<pair<int64_t, int>> S, T;
    for (int i = 0; i < K; ++i) {
        S.emplace(0, i);
    }
    for (int i = K; i < N; ++i) {
        T.emplace(0, i);
    }
    while (Q--) {
        int64_t x, y;
        cin >> x >> y;
        if (S.count(make_pair(A[x - 1], x - 1))) {
            ans -= A[x - 1];
            S.erase(make_pair(A[x - 1], x - 1));
            A[x - 1] = y;
            S.emplace(y, x - 1);
            ans += A[x - 1];
        } else {
            T.erase(make_pair(-A[x - 1], x - 1));
            A[x - 1] = y;
            T.emplace(-y, x - 1);
        }
        auto it1 = S.begin();
        auto it2 = T.begin();
        if ((it2 != T.end()) && ((it1 -> first) < -(it2 -> first))) {
            ans -= (it2 -> first) + (it1 -> first);
            S.emplace(-(it2 -> first), it2 -> second);
            T.emplace(-(it1 -> first), it1 -> second);
            S.erase(it1), T.erase(it2);
        }
        cout << ans << "\n";
    }
}
