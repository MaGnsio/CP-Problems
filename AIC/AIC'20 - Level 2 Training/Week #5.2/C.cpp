//https://vjudge.net/contest/435128#problem/C
#include <bits/stdc++.h>
using namespace std;

void solve(string s, vector<string>& v, int idx = 0, string t = "") {
    if (idx == s.size()) {
        if (!t.empty ()) {
            v.push_back(t);
        }
        return;
    }
    solve(s, v, idx + 1, t + s[idx]);
    solve(s, v, idx + 1, t);
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    vector<string> V;
    string S;
    cin >> S;
    solve(S, V);
    sort(V.begin(), V.end());
    for (auto& X : V) {
        cout << X << "\n";
    }
}

