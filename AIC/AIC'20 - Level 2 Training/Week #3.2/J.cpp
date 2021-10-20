//https://vjudge.net/contest/419723#problem/J
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
    ll t;
    cin >> t;
    while (t--)
    {
        ll x, k;
        cin >> x >> k;
        if (x >= k)
        {
            cout << k - (x % k) << " " << (x % k) << "\n"; //let floor(x / k) = a -> ceil (x / k) = a + 1 -> (k * a) - ((x % k) * a) + ((x % k) * (a + 1)) = (k * a) + (x % k) = x
        }
        else cout << 0 << " " << x << "\n"; //(0 * 0) + (1 * x) == x
    }
}

