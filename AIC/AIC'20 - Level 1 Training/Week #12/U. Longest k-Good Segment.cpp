//https://codeforces.com/group/Rv2Qzg0DgK/contest/292431/problem/U
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
    ll n, k, c = 0, j = 0, l = 0;
    cin >> n >> k;
    ll a[n], freq[1000010] = {};
    for (auto& elem : a) cin >> elem;
    pair<ll, ll> ans = {1, 1};
    for (ll i = 0; i < n; ++i)
    {
        if (++freq[a[i]] == 1) c++;
        if (c > k)
        {
            while (true)
            {
                if (!--freq[a[j]])
                {
                    c--, j++;
                    break;
                }
                j++;
            }
        }
        if (i - j + 1 > l) l = i - j + 1, ans = {j + 1, i + 1};
    }
    cout << ans.F << " " << ans.S;
}

