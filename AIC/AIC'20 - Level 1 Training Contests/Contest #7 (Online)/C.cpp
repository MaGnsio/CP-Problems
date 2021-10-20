//https://codeforces.com/group/aDFQm4ed6d/contest/275835/problem/C
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
    ll sum = 0, i = 0;
    string s;
    cin >> s;
    for (; i < s.size (); ++i) if (s[i] == ':') break;
    for (; i < s.size (); ++i)
    {
        ll temp = 0;
        while (s[i] >= '0' && s[i] <= '9' && i < s.size ()) temp = temp * 10 + (s[i++] - '0');
        sum += temp;
    }
    cout << sum;
}

