//https://codeforces.com/group/aDFQm4ed6d/contest/288718/problem/H
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;


bool isvowel (char c)
{
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
    return false;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s;
    cin >> s;
    ll i = 0, j = 0, cnt = 0, ma = 0;
    while (i <= j && j < s.size ())
    {
        ll l = 0;
        while (isvowel (s[j]) && j < s.size ()) j++, l++;
        cnt += l * (l + 1) / 2;
        ma = max (ma, l);
        i = j = j + 1;
    }
    cout << cnt << " " << ma;
}

