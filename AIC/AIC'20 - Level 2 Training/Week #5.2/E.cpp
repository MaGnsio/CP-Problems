//https://vjudge.net/contest/435128#problem/E
#include <bits/stdc++.h>
using namespace std;

void solve(int& n, int& x, int& sum, int& ok, vector<int>& v, int idx = 1) {
    if (idx == n) {
        if (sum == x) {
            ok = 1;
        }
        return;
    }
    sum += v[idx];
    solve(n, x, sum, ok, v, idx + 1);
    sum -= (2 * v[idx]);
    solve(n, x, sum, ok, v, idx + 1);
    sum += v[idx];
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (auto& e : v) {
        cin >> e;
    }
    int sum = v[0], ok = 0;
    solve(n, x, sum, ok, v);
    cout << (ok ? "YES" : "NO");
}

