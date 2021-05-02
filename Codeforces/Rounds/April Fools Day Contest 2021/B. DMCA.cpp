//https://codeforces.com/contest/1505/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, x = 0;
    cin >> n;
    while (n > 9)
    {
        while (n) x += (n % 10), n /= 10;
        n = x, x = 0;
    }
    cout << n;
}

