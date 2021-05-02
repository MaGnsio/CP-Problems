//https://codeforces.com/group/aDFQm4ed6d/contest/298276/problem/F
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

bool chk (string s)
{
    if (s.size () & 1) return true;
    size_t sz = s.size () / 2;
    string x = s.substr (0, sz), y = s.substr (s.size () / 2, sz);
    return x != y;
} 

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int cnt = 1;
    string s;
    cin >> s;
    s.erase (s.size () - 1, 1);
    while (chk (s))
    {
        s.erase (s.size () - 1, 1);
        cnt++;
    }
    cout << cnt;
}

