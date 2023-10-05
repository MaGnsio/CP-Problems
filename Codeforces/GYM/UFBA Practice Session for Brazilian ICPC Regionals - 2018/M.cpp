/**
 *    author:  MaGnsi0
 *    created: 06.09.2023 02:45:51
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    int cost = n, m = 4;
    vector<vector<pair<int, int>>> ans;
    while (m < n) {
        ans.push_back({});
        int i = 1;
        while (i <= n) {
            int j = min(i + m - 1, n);
            ans.back().emplace_back(i, j);
            i = j + 1;
        }
        cost += m;
        m *= 4;
    }
    assert(cost <= 7 * n);
    ans.push_back({make_pair(1, n)});
    int k = (int)ans.size();
    assert(k <= 10);
    cout << k << "\n";
    for (auto op : ans) {
        cout << (int)op.size() << "\n";
        for (auto [L, R] : op) {
            cout << L << " " << R << "\n";
        }
    }
}
