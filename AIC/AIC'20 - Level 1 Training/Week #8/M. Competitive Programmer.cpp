//https://codeforces.com/group/Rv2Qzg0DgK/contest/286457/problem/M
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

void solve ()
{
    int sum = 0, zeros = 0, evens = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.size (); ++i)
    {
        if (s[i] - '0' == 0) zeros++;
        if ((s[i] - '0') % 2 == 0) evens++;
        sum += (s[i] - '0');
    }
    if (zeros && evens > 1 && (sum % 3 == 0)) cout << "red\n";
    else cout << "cyan\n";
}
int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
    {
        solve ();
    }
}

