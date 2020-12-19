//https://codeforces.com/group/Rv2Qzg0DgK/contest/273155/problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, meh = 0, msf = LLONG_MIN;
    cin >> n;
    vector<ll> v(n);
    for (auto& elem : v) cin >> elem;
    //Kadane’s algorithm
    for (ll i = 0; i < n; ++i)
    {
        meh += v[i];
        if (msf < meh) msf = meh;
        if (meh < 0) meh = 0;
    }
    cout << msf;
}

