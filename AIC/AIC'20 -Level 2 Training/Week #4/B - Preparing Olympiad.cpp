//https://vjudge.net/contest/433102#problem/B
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long n, l, r, x, ans = 0;
    cin >> n >> l >> r >> x;
    vector<long long> v(n);
    for (auto& x : v) {
        cin >> x;
    }
    for (long long mask = 0; mask < (1 << n); ++mask) {
        long long tot = 0, cnt = 0, mini = LLONG_MAX, maxi = LLONG_MIN;
        for (long long j = 0; j < n; ++j) {
            if ((1 << j) & mask) {
                tot += v[j];
                mini = min (mini, v[j]);
                maxi = max (maxi, v[j]);
                cnt++;
            }
        }
        if (cnt >= 2 && tot >= l && tot <= r && maxi - mini >= x) {
            ans++;
        }
    }
    cout << ans;
}

