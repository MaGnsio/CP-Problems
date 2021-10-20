//https://vjudge.net/contest/419723#problem/A
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
    ll n;
    cin >> n;
    vector<ll> v;
    for (ll i = 1; i * i <= n; ++i)
    {
        if (n % i == 0)
        {
            v.push_back ((1 + (n + 1 - i)) * (n / i) / 2);
            if (i * i != n) v.push_back ((1 + (n + 1 - (n / i))) * (n / (n / i)) / 2);
        }
    }
    sort (v.begin (), v.end ());
    for (auto& x : v) cout << x << " ";
}

