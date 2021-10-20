/**
 *    author:  MaGnsi0
 *    created: 17/07/2021 13:36:37
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(set<int>& s, int x, vector<int>& b, int i = 0) {
    if (i == b.size()) {
        s.insert(x);
        return;
    }
    solve(s, (x ^ (1LL << (b[i] - 1LL))), b, i + 1);
    solve(s, x, b, i + 1);
}

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, x;
    cin >> n >> x;
    vector<int> b(n);
    for (auto& l : b) {
        cin >> l;
    }
    set<int> s;
    solve(s, x, b);
    for (auto& l : s) {
        cout << l << "\n";
    }
}
