//https://codeforces.com/group/aDFQm4ed6d/contest/275835/problem/F
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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m), p;
    for (auto& X : a) cin >> X;
    for (auto& X : b) cin >> X;
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            if (b[j] == a[i])
            {
                p.push_back (a[i]);
                break;
            }
        }
    }
    for (auto& X : p) cout << X << " ";
}

