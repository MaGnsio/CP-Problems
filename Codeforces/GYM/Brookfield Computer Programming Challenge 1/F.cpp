//https://codeforces.com/gym/102680/problem/F
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, u, start = 1;
    cin >> n >> u;
    vector<pair<long, long>> v(u);
    if (u == 0) {
        cout << n;
        return 0;
    }
    for (auto& x : v) cin >> x.first >> x.second;
    sort (v.begin (), v.end ());
    if (v[0].first != 1) {
        cout << 1;
        return 0;
    }
    if (v[u - 1].second != n) {
        cout << n;
        return 0;
    }
    for (long long i = 0; i < n; ++i) {
        if (v[i].first <= start + 1) {
            start = v[i].second;
            continue;
        }
        cout << start + 1;
        return 0;
    }
}

