//https://vjudge.net/contest/435128#problem/D
#include <bits/stdc++.h>
using namespace std;
const int MAX = 22;

void solve(int& n, int& r, vector<string>& s, vector<string>& v, int idx = 0) {
    if (idx == n) {
        if (v.size() == r) {
            for (auto& x : v) {
                cout << x << " ";
            }
            cout << "\n";
        }
        return;
    }
    v.push_back(s[idx]);
    solve(n, r, s, v, idx + 1);
    v.pop_back();
    solve(n, r, s, v, idx + 1);
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, r;
    cin >> n >> r;
    vector<string> s(n), v;
    for (auto& x : s) {
        cin >> x;
    }
    sort(s.begin(), s.end());
    solve(n, r, s, v);
}

