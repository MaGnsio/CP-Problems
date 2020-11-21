//https://codeforces.com/group/nVgev28wQI/contest/303358/problem/D
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    freopen ("cell.in", "r", stdin);
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll t;
    cin >> t;
    while(t--)
    {
        ll a, b, sum = 1, c = 0;
        cin >> a >> b;
        while(sum < a)
        {
            c++;
            sum *= b;
        }
        cout << c << "\n";
    }
}

