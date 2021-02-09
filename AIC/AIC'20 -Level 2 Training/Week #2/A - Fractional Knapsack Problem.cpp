//https://vjudge.net/contest/417978#problem/A
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
    ll N;
    ld W, V = 0, C = 0;
    cin >> N >> W;
    pair<ld, ld> a[N];
    for (auto& X : a)
    {
        cin >> X.F >> X.S;
        X.F /= X.S;
    }
    sort (a, a + N);
    for (ll i = N - 1; i >= 0; --i)
    {
        if (C > W + 1e-9) break;
        ld w = min (W - C, a[i].S);
        C += w, V += w * a[i].F;
    }
    cout << fixed << setprecision (8) << V;
}

