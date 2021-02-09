//https://vjudge.net/contest/416254#problem/X
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
    ll n;
    cin >> n;
    cout << n - (n / 2) - (n / 3) - (n / 5) - (n / 7) + (n / (2 * 3)) + (n / (2 * 5)) + (n / (2 * 7)) + (n / (3 * 5)) + (n / (3 * 7)) + (n / (5 * 7)) - (n / (2 * 3 * 5)) - (n / (2 * 3 * 7)) - (n / (2 * 5 * 7)) - (n / (3 * 5 * 7)) + (n / (2 * 3 * 5 * 7));
}

