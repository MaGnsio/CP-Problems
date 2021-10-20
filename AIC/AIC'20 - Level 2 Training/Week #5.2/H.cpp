//https://vjudge.net/contest/435128#problem/H
#include <bits/stdc++.h>
using namespace std;

void solve(int& n, int& maxi, vector<int>& v, vector<int>& f, int idx = 0) {
    if (idx == n) {
        maxi = max(maxi, (int) f.size());
        return;
    }
    if (!f.empty() && v[idx] <= f.back()) {
        solve(n, maxi, v, f, idx + 1);
    } else {
        solve(n, maxi, v, f, idx + 1);
        f.push_back(v[idx]);
        solve(n, maxi, v, f, idx + 1);
        f.pop_back();
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, maxi = INT_MIN;
    cin >> n;
    vector<int> v(n), f;
    for (auto& x : v) {
        cin >> x;
    }
    solve(n, maxi, v, f);
    cout << maxi;
}

