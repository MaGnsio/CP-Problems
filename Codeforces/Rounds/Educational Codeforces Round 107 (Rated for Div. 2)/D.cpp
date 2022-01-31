/**
 *    author:  MaGnsi0
 *    created: 17.01.2022 00:15:53
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> cnt(k, 0), best;
    function<void(int)> dfs = [&](int v) {
        while (cnt[v] < k) {
            int u = cnt[v]++;
            dfs(u);
            best.push_back(u);
        }
    };
    dfs(0);
    cout << 'a';
    for (int i = 0; i < n - 1; ++i) {
        cout << char('a' + best[i % (int)best.size()]);
    }
}
