//https://vjudge.net/contest/421809#problem/H
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
    cin >> n >> s;
    s = "*" + s + "*";
    for (char i = 'z'; i > 'a'; --i)
    {
        for (ll j = 1; j < s.size () - 1; ++j)
        {
            if (s[j] == i && (s[j - 1] == i - 1 || s[j + 1] == i - 1))
            {
                s = s.substr (0, j) + s.substr (j + 1);
                i++;
                break;
            }
        }
    }
    cout << n + 2 - s.size ();
}

