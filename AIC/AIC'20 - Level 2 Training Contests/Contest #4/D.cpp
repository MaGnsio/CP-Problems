//https://vjudge.net/contest/417537#problem/D
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
    ll n, x;
    vector<ll> v;
    cin >> n;
    for (ll i = 0; i < n; ++i)
    {
        cin >> x;
        if (x == v.size () + 1) v.push_back (2001 + i);
    }
    if (v.size () == 0) cout << 0;
    else
    {
        cout << v.size () << "\n";
        for (auto& elem : v) cout << elem << " ";
    }

}
