//https://vjudge.net/contest/419722#problem/W
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
    ll n, i, cnt = 0;
    cin >> n;
    for (i = 1; i * i < n; ++i) if (n % i == 0) cnt += 2;
    cout << (i * i == n ? ++cnt : cnt);
}

