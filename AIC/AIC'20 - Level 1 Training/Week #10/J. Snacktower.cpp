//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/J
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
    ll n, cur;
    cin >> n;
    cur = n;
    vector<ll> v(n);
    priority_queue<ll> q;
    for (auto& elem : v) cin >> elem;
    for (ll i = 0; i < n; ++i)
    {
        q.push (v[i]);
        while (!q.empty () && q.top () == cur)
        {
            cout << q.top () << " ";
            cur--;
            q.pop ();
        }
        if (i != n - 1) cout << "\n";
    }
}

