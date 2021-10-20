//https://vjudge.net/contest/416230#problem/W
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll multiply (ll x, ll res[], ll res_size) 
{ 
    ll carry = 0;
    for (ll i = 0; i < res_size; ++i) 
    { 
        ll prod = res[i] * x + carry; 
        res[i] = prod % 10;   
        carry  = prod / 10;     
    } 
    while (carry) 
    { 
        res[res_size] = carry % 10; 
        carry = carry / 10; 
        res_size++; 
    } 
    return res_size; 
} 
void f (ll n) 
{ 
    ll res[100000]; 
    res[0] = 1; 
    ll res_size = 1; 
    for (ll x = 2; x <= n; ++x) res_size = multiply (x, res, res_size); 
    for (ll i = res_size - 1; i >= 0; --i) cout << res[i];
    cout << "\n";
} 
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        f (n);
    }
}

