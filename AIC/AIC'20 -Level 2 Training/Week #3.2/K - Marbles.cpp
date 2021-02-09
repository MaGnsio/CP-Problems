//https://vjudge.net/contest/419723#problem/K
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll EE (ll a, ll b, ll& x, ll& y)
{
  if (b == 0)
  {
    x = 1, y = 0;
    return a;
  }
  ll x1, y1;
  ll gcd = EE (b, a % b, x1, y1);
  x = y1;
  y = x1 - (a / b) * y1;
  return gcd;
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, c1, n1, c2, n2;
    while (cin >> n >> c1 >> n1 >> c2 >> n2 )
    {
        ll x, y;
        ll gcd = EE (n1, n2, x, y);
        if (n % gcd != 0) cout << "failed\n";
        else
        {
            ll t1 = (ll) ceil (-(double) x * n / n2);
            ll t2 = (ll) floor ((double) y * n / n1);
            if (t1 > t2) cout << "failed\n";
            else
            {
                ll cost1 = (n / gcd) * (c1 * x + c2 * y) + t1 * (c1 * n2 - c2 * n1) / gcd;
                ll cost2 = (n / gcd) * (c1 * x + c2 * y) + t2 * (c1 * n2 - c2 * n1) / gcd;
                ll t;
                if (cost1 > cost2) t = t2;
                else t = t1;
                ll m1 = (x * n + n2 * t) / gcd;
                ll m2 = (y * n - n1 * t) / gcd;
                cout << m1 << " " << m2 << "\n";
            }
        }
    }
}
/****************************************************EXPLANTION****************************************************
 * x0 * n1 + y0 * n2 = g --> x0 * (n / g) * n1 + y0 * (n / g) * n2 = n (solvable iff n is divisble by gcd (n1, n2))
 * using bezout's identity that states that X = X0 + t * n2 / gcd, Y = Y0 - t * n1 / gcd --> X = x0 * (n / g) + t * n2 / gcd, Y = y0 - t * n1 / gcd : X, Y (amount of boxes) >= 0
 * now as we want to get the minimum cost we should search for t that make the cost as small as possible
 * knowing that: -x0 * n / n2 <= t <= y0 * n / n1, we find which bound that is cost is as small as possible at
 */
