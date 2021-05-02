//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/P
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;
string I = "insert";
string G = "getMin";
string R = "removeMin";

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, x;
    cin >> n;
    vector<pair<string, ll>> v;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (ll i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        if (s == I)
        {
            cin >> x;
            q.push (x);
            v.push_back ({I, x});
        }
        else if (s == G)
        {
            cin >> x;
            while (!q.empty () && q.top () < x)
            {
                q.pop ();
                v.push_back ({R, 2e9});
            }
            if (q.empty () || q.top () > x)
            {
                q.push (x);
                v.push_back ({I, x});
            }
            v.push_back ({s, x});
        }
        else
        {
            if (q.empty ()) v.push_back ({I, 0});
            else q.pop ();
            v.push_back ({s, 2e9});
        }
    }
    cout << v.size () << "\n";
    for (auto& x : v)
    {
        cout << x.F;
        if (x.S != 2e9) cout << " " << x.S;
        cout << "\n";
    }
}

