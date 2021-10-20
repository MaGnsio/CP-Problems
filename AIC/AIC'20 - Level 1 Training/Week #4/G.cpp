//https://codeforces.com/group/Rv2Qzg0DgK/contest/273155/problem/G
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
    ll n, sum = 0, m1 = 0, m2 = 0;
    cin >> n;
    vector<ll> a(n), v;
    for (auto& elem : a)
    {
        cin >> elem;
        sum += elem;
        if (m1 <= elem)
        {
            m2 = m1;
            m1 = elem;
        }
        else if (m2 < elem) m2 = elem;
    }
    for (ll i = 0; i < n; ++i)
    {
        if (sum - a[i] - (a[i] == m1 ? m2 : m1) == (a[i] == m1 ? m2 : m1)) v.push_back (i + 1);
    }
    cout << v.size () << "\n";
    for (auto& elem : v) cout << elem << " ";
}

