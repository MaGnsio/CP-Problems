//https://codeforces.com/group/Rv2Qzg0DgK/contest/285699/problem/J
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
    int ans = 0;
    int dpa[5'002] = {}, dpb[5'002] = {};
    string s;
    cin >> s;
    for (int i = 0; i < s.size (); ++i)
    {
        if (s[i] == 'a') dpa[i + 1] = dpa[i] + 1, dpb[i + 1] = dpb[i];
        else dpa[i + 1] = dpa[i], dpb[i + 1] = dpb[i] + 1;
    }
    for (int i = 0; i <= s.size (); ++i)
    {
        for (int j = i; j <= s.size (); ++j)
        {
            ans = max (ans, (dpa[i]) + (dpb[j] - dpb[i]) + (dpa[s.size ()] - dpa[j]));
        }
    }
    cout << ans;
}

