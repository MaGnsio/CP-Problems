//https://vjudge.net/contest/417978#problem/E
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

ll N;
char A[20][20];
char p = 'A';

bool chk (ll i, ll j)
{
    if ((A[i - 1][j] == p && i - 1 >= 0)
      ||(A[i + 1][j] == p && i + 1 < N)
      ||(A[i][j - 1] == p && j - 1 >= 0)
      ||(A[i][j + 1] == p && j + 1 < N)) return true;
    else return false;
}

void solve (ll i)
{
    cin >> N;
    for (ll i = 0; i < N; ++i)
    {
        for (ll j = 0; j < N; ++j) cin >> A[i][j];
    }
    for (ll i = 0; i < N; ++i)
    {
        for (ll j = 0; j < N; ++j)
        {
            if (A[i][j] == '.')
            {
                while (chk (i, j)) p = char (p + 1);
                A[i][j] = p, p = 'A';
            }
        }
    }
    cout << "Case " << i << ":\n";
    for (ll i = 0; i < N; ++i)
    {
        for (ll j = 0; j < N; ++j) cout << A[i][j];
        cout << "\n";
    }
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t, i = 0;
    cin >> t;
    while (t--) solve (++i);
}

