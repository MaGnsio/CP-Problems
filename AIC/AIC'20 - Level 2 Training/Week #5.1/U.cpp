//https://vjudge.net/contest/434102#problem/U
#include <bits/stdc++.h>
using namespace std;

bool comp (pair<long long, long long> a, pair<long long, long long> b) {
    return (a.first * b.second <= a.second * b.first);
}


void solve (long long n, vector<pair<long long, long long>>& a, long long v, long long m, long long& ans, long long sum = 0, long long temp = 0, long long i = 0) {
    if (sum >= v) {
        ans = min (ans, temp);
        return;
    }
    if (i == n) {
        return;
    }
    solve (n, a, v, m, ans, sum, temp, i + 1);
    solve (n, a, v, m, ans, sum + (m * a[i].first), temp + a[i].second, i + 1);
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n;
    cin >> n;
    vector<pair<long long, long long>> a(n);
    for (auto& x : a) {
        cin >> x.first >> x.second;
    }
    long long q;
    cin >> q;
    for (long long i = 1; i <= q; ++i) {
        long long v, m, ans = LLONG_MAX;
        cin >> v >> m;
        solve (n, a, v, m, ans);
        cout << "Case " << i << ": ";
        if (ans == LLONG_MAX) {
            cout << "IMPOSSIBLE\n";
        } else {
            cout << ans << "\n";
        }
    }
}

