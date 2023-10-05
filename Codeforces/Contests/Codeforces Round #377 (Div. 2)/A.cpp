//https://codeforces.com/problemset/problem/732/A
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
    int k, r;
    cin >> k >> r;
    for (int i = 1; i <= 10; ++i) if ((k * i) % 10 == 0 || (k * i) % 10 == r) return cout << i, 0;
}

