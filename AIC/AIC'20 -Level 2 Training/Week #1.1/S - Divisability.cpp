//https://vjudge.net/contest/416230#problem/S
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll f (ll a, ll k) 
{ 
    ll r = a % k; 
    if (!r) return a; 
    else return a - r;
} 
ll s (ll b, ll k) 
{ 
    ll r = (b + k) % k; 
    if (!r) return b;
    else return b + k - r;
}
ll d (ll a, ll b, ll k) 
{ 
    ll sum = 0, x = f (a, k), y = s (b, k); 
    if (x < a) x += k;
    if (y > b) y -= k;
    ll n = (b / k) - (a - 1) / k; 
    return n * (x + y) / 2; 
} 
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap (a, b);
    cout << d (a, b, c);
}

