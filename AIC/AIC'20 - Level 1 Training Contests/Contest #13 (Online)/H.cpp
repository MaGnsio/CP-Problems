//https://codeforces.com/group/aDFQm4ed6d/contest/286323/problem/H
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

struct data
{
    string n;
    int a, b, c, d;
    int sum;
};

bool comp (struct data x, struct data y) {return ((x.sum > y.sum) || (x.sum == y.sum && x.n < y.n));}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    struct data f[n];
    for (auto& x : f)
    {
        cin >> x.n >> x.a >> x.b >> x.c >> x.d;
        x.sum = x.a + x.b + x.c + x.d;
    }
    sort (f, f + n, comp);
    for (auto& x : f) cout << x.n << " " << x.sum << " " << x.a << " " << x.b << " " << x.c << " " << x.d << "\n";
}

