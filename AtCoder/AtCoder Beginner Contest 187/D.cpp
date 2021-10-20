//https://atcoder.jp/contests/abc187/tasks/abc187_d
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

bool comp (pair<ll, ll> a, pair<ll, ll> b) {return (2 * a.F + a.S > 2 * b.F + b.S);}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n;
    cin >> n;
    pair<ll, ll> a[n];
    for (auto& x : a) cin >> x.F >> x.S;
    sort (a, a + n, comp);
    ll A = 0, T = 0, cnt = 0;
    for (auto& x : a) A += x.F;
    for (auto& x : a)
    {
        A -= x.F, T += (x.F + x.S);
        cnt++;
        if (T > A) break;
    }
    cout << cnt;
}

