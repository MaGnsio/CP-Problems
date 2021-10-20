//https://vjudge.net/contest/416230#problem/G
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
    ll lines;
    cin >> lines;
    for (ll line = 1; line <= lines; line++)
    {
        ll c = 1;
        for (ll i = 1; i <= line; i++)
        {
            cout << c << " ";
            c = c * (line - i) / i;
        }
        cout << "\n";
    }
}

