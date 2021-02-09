//https://vjudge.net/contest/417978#problem/H
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
    ll n, r = 0;
    string s;
    cin >> n >> s;
    if (n == 1) return cout << 0 << "\n" << s, 0;
    if (n == 2)
    {
        if (s[0] == s[1])
        {
            if (s[0] == 'R') s[1] = 'G';
            else s[1] = 'R';
            return cout << 1 << "\n" << s, 0;
        }
        return cout << 0 << "\n" << s, 0;
    }
    for (ll i = 1; i < n; ++i)
    {
        if (s[i - 1] == s[i])
        {
            if (s[i - 1] != 'R' && (s[i + 1] != 'R' || i == n - 1)) s[i] = 'R';
            else if (s[i - 1] != 'G' && (s[i + 1] != 'G' || i == n - 1)) s[i] = 'G';
            else s[i] = 'B';
            r++;
        }
    }
    cout << r << "\n" << s;
}

