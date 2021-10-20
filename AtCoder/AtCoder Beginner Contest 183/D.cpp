//https://atcoder.jp/contests/abc183/tasks/abc183_d
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7, sz = 2e5 + 1;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll N, W;
    vector<ll> T (sz, 0);
    cin >> N >> W;
    for (ll i = 0; i < N; ++i) {
        ll s, t, r;
        cin >> s >> t >> r;
        T[s] += r, T[t] -= r;
    }
    for (ll i = 1; i < sz; ++i) {
        T[i] += T[i - 1];
    }
    for (auto& x : T) {
        if (x > W) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
}

