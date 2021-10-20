//https://vjudge.net/contest/435128#problem/G
#include <bits/stdc++.h>
using namespace std;

void solve(int& n, vector<int>& v, vector<int>& f, vector<vector<int>>& s, int idx = 0) {
    if (idx == n) {
        if (!f.empty()) {
            s.push_back(f);
        }
        return;
    }
    if (!f.empty() && v[idx] <= f.back()) {
        solve(n, v, f, s, idx + 1);
    } else {
        solve(n, v, f, s, idx + 1);
        f.push_back(v[idx]);
        solve(n, v, f, s, idx + 1);
        f.pop_back();
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<int> v(n), f;
    vector<vector<int>> s;
    for (auto& x : v) {
        cin >> x;
    }
    solve(n, v, f, s);
    sort(s.begin(), s.end());
    for (auto& a : s) {
        for (auto& x : a) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

