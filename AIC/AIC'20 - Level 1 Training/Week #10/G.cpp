//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/G
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
    string s;
    deque<string> q;
    set <string> _s;
    cin >> n;
    while (n--)
    {
        cin >> s;
        q.push_back (s);
    }
    while (!q.empty ())
    {
        if (!_s.count (q.back ())) cout << q.back () << "\n";
        _s.insert (q.back ());
        q.pop_back ();
    }
}

