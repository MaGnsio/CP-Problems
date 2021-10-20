//https://codeforces.com/group/aDFQm4ed6d/contest/287686/problem/E
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, ans = INT_MAX;
    string s, res, x = "BGR";
    cin >> n >> s;
    do
    {
        int cnt = 0;
        string t = s;
        for (int i = 0; i < n; ++i)
        {
            t[i] = x[i % 3];
            cnt += (t[i] != s[i]);
        }
        if (ans > cnt)
        {
            ans = cnt;
            res = t;
        }
    } while (next_permutation (x.begin (), x.end ()));
    cout << ans << "\n" << res;
}

