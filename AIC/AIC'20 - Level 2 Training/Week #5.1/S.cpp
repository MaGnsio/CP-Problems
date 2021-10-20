//https://vjudge.net/contest/434102#problem/S
#include <bits/stdc++.h>
using namespace std;

void solve (int& n, vector<string>& v, int o = 0, string s = "") {
    if (s.size () == 2 * n) {
        if (!o) {
            v.push_back (s);
        }
        return;
    }
    solve (n, v, o + 1, s + "(");
    if (o) {
        solve (n, v, o - 1, s + ")");
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    vector<string> v;
    cin >> n;
    solve (n, v);
    for (auto& x : v) {
        cout << x << "\n";
    }
}

