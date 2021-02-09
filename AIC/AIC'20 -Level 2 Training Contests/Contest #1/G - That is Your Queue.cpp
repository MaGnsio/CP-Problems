//https://vjudge.net/contest/414669#problem/G
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve (ll p, ll c, ll t)
{
    ll x;
    char in;
    deque<ll> q;
    for (ll i = 1; i <= min (p, 1000ll); ++i) q.push_back (i);
    cout << "Case " << t << ":\n";
    while (c--)
    {
        cin >> in;
        if (in == 'N')
        {
            x = q.front ();
            q.pop_front ();
            q.push_back (x);
            cout << x << "\n";
        }
        else
        {
            cin >> x;
            for (auto i = q.begin (); i != q.end (); ++i) if (*i == x) {q.erase (i); break;}
            q.push_front (x);
        }
    }
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll p, c, t = 1;
    while (cin >> p >> c && !(p == 0 && c == 0)) solve (p, c, t++);
}

