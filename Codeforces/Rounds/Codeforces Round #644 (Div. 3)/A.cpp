//https://codeforces.com/problemset/problem/1360/A
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
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        cout << min (max ((a + a) * (a + a), b * b), max ((b + b) * (b + b), a * a)) << "\n";
    }
}

