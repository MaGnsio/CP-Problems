//https://vjudge.net/contest/435043#problem/B
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    string l, r;
    cin >> n >> l >> r;
    vector<pair<int, int>> v;
    vector<vector<int>> f(27);
    vector<int> d;
    for (int i = 0; i < n; ++i) {
        if (l[i] == '?') {
            f[26].push_back (i + 1);
        } else {
            f[l[i] - 'a'].push_back (i + 1);
        }
    }
    for (int i = 0; i < n; ++i) {
        if (r[i] == '?') {
            d.push_back (i + 1);
            continue;
        }
        if (f[r[i] - 'a'].empty() && f[26].empty()) {
            continue;
        }
        if (!f[r[i] - 'a'].empty ()) {
            v.push_back({f[r[i] - 'a'][0], i + 1});
            l[f[r[i] - 'a'][0] - 1] = '0';
            f[r[i] - 'a'].erase(f[r[i] - 'a'].begin());
        } else {
            v.push_back({f[26][0], i + 1});
            l[f[26][0] - 1] = '0';
            f[26].erase(f[26].begin());
        }
    }
    for (int i = 0; i < n && !d.empty (); ++i) {
        if (l[i] == '0') {
            continue;
        }
        v.push_back ({i + 1, d[0]});
        d.erase (d.begin ());
    }
    cout << v.size();
    for (auto& x : v) {
        cout << "\n" << x.first << " " << x.second;
    }
}

