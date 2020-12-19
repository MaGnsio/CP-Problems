//https://codeforces.com/group/Rv2Qzg0DgK/contest/273155/problem/K
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
    ll x, y;
    bool bx = false, by = false;
    string s;
    cin >> x >> y >> s;
    if ((((x > 0 && count (s.begin (), s.end (), 'R') >= x) && (y > 0 && count (s.begin (), s.end (), 'F') >= y))
        || ((x > 0 && count (s.begin (), s.end (), 'R') >= x) && (y < 0 && count (s.begin (), s.end (), 'B') >= abs (y)))
        || ((x < 0 && count (s.begin (), s.end (), 'L') >= abs (x)) && (y > 0 && count (s.begin (), s.end (), 'F') >= y))
        || ((x < 0 && count (s.begin (), s.end (), 'L') >= abs (x)) && (y < 0 && count (s.begin (), s.end (), 'B') >= abs (y)))
        || ((x == 0) && (y > 0 && count (s.begin (), s.end (), 'F') >= y))
        || ((x == 0) && (y < 0 && count (s.begin (), s.end (), 'B') >= abs (y)))
        || ((x == 0) && (y == 0))
        || ((x > 0 && count (s.begin (), s.end (), 'R') >= x) && (y == 0))
        || ((x < 0 && count (s.begin (), s.end (), 'L') >= abs (x)) && (y == 0)))
        && ((count (s.begin (), s.end (), 'R') - count (s.begin (), s.end (), 'L') == 0) && (count (s.begin (), s.end (), 'F') - count (s.begin (), s.end (), 'B') == 0))) cout << "YES";
    else cout << "NO";
}

