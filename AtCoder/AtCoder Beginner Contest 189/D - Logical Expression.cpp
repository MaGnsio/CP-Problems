//https://atcoder.jp/contests/abc189/tasks/abc189_d
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
    ll n, cnt = 1;
    string s;
    cin >> n;
    for (ll i = 1; i <= n; ++i)
    {
        cin >> s;
        if (s == "OR") cnt += (1LL << i);
    }
    cout << cnt;
}

