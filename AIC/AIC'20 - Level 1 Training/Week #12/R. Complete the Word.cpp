//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/R
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;
//GLOBAL VARIABLES
string s;
//CALCULATE HOW MANY UNIQUE CHARACTERS IN A SUBSTRING
ll sum (ll a[])
{
    ll s1 = 0;
    for (ll i = 0; i < 26; ++i) s1 += (a[i] ? 1 : 0);
    return s1;
}
//CHANGE '?' TO THE MISSING CHARACTERS
void get (ll a[], ll l, ll r)
{
    for (ll i = 0; i < 26; ++i)
    {
        if (!a[i])
        {
            bool got = false;
            for (int j = l; j < r; j++)
            {
                if (s[j] == '?')
                {
                    s[j] = i + 'A';
                    got = true;
                }
                if (got) break;
            }
        }
    }
}
//SOLVE
void solve ()
{
    cin >> s;
    //IF THE SIZE OF STRING LESS THAN 26, THE STRING CAN't HAVE A NICE WORD
    if (s.size () < 26)
    {
        cout << -1;
        return;
    }
    //CHECK IF THE FIRST 26 CHARACTERS (0 -> 25) CAN FORM A NICE WORD OR NOT
    ll qcnt = 0;
    ll a[26] = {};
    for (ll i = 0; i < 26; ++i)
    {
        if (isalpha (s[i])) a[s[i] - 'A']++;
        else qcnt++;
    }
    if (sum (a) + qcnt == 26)
    {
        get (a, 0, 26);
        for (auto& elem : s) if (elem == '?') elem = 'A';
        cout << s;
        return;
    }
    //CHECK IF THE OTHER SUBSTRINGS (1 -> 26, 2 -> 27, n - 26 -> n - 1) CAN FORM A NICE WORD OR NOT
    for (ll i = 26; i < s.size (); ++i)
    {
        if (isalpha (s[i])) a[s[i] - 'A']++;
        else qcnt++;
        if (isalpha (s[i - 26])) a[s[i - 26] - 'A']--;
        else qcnt--;
        if (sum (a) + qcnt == 26)
        {
            get(a, i - 26 + 1, i + 1);
            for (auto& elem : s) if (elem == '?') elem = 'A';
            cout << s;
            return;
        }
    }
    cout << -1;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    solve ();
}

