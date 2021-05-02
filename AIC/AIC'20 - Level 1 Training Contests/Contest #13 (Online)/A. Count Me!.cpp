//https://codeforces.com/group/aDFQm4ed6d/contest/286323/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

bool comp (int a, int b) {return ((abs (a) < abs (b)) || (abs (a) == abs (b) && a < b));}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    int a[n];
    for (auto& x : a) cin >> x;
    sort (a, a + n, comp);
    int cnt = (a[0] > 0);
    for (int i = 1; i < n; ++i)
    {
        if (a[i] > 0 && abs (a[i]) != abs (a[i - 1])) cnt++;
    }
    cout << cnt;
}

