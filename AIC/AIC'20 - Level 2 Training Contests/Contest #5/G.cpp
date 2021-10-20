//https://vjudge.net/contest/418569#problem/G
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
    ll n, sz = 0;
    string s;
    cin >> n;
    vector<string> v(n), c;
    for (auto& X : v) cin >> X;
    cin >> s;
    for (auto& X : v) sz += X.size ();
    sz /= (n / 2);
    sort (v.begin (), v.end ());
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = i + 1; j < n; ++j)
        {
            if (v[i].size () + v[j].size () == sz)
            {
                c.push_back (min (v[i] + s + v[j], v[j] + s + v[i]));
                v[j] = "";
                break;
            }
        }
    }
    sort (c.begin (), c.end ());
    for (auto& X : c) cout << X << "\n";
}

