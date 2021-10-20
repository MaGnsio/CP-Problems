//https://vjudge.net/contest/417978#problem/O
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
    ll n, m;
    cin >> n >> m;
    ll B[n][m], A[n][m] = {1};
    for (auto& R : A) for (auto& X : R) X = 1;
    for (auto& R : B) for (auto& X : R) cin >> X;
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            if (!B[i][j])
            {
                for (ll k = 0; k < n; ++k) A[k][j] = 0;
                for (ll t = 0; t < m; ++t) A[i][t] = 0;
            }
        }
    }
    for (ll i = 0; i < n; ++i)
    {
        for (ll j = 0; j < m; ++j)
        {
            ll x = 0;
            for (ll k = 0; k < n; ++k) x |= A[k][j];
            for (ll t = 0; t < m; ++t) x |= A[i][t];
            if (x != B[i][j]) return cout << "NO", 0;
        }
    }
    cout << "YES\n";
    for (auto& R : A)
    {
        for (auto& X : R) cout << X << " ";
        cout << "\n";
    }
}

