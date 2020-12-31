//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

bool RBN (ll x, ll s)
{
    ll y = x, sum = 0;
    while (y) sum += (y % 10), y /= 10;
    return x - sum >= s;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, s, p = -1;
    cin >> n >> s;
    ll l = 1, r = n, mid;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (RBN (mid, s)) r = mid - 1, p = mid;
        else l = mid + 1;
    }
    cout << (p == -1 ? 0 : n - p + 1);
}

