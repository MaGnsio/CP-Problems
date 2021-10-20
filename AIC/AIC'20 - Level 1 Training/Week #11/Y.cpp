//https://codeforces.com/group/Rv2Qzg0DgK/contest/291373/problem/Y
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ll n;
    cin >> n;
    ll l = 1, r = n, m;
    string s;
    while (l < r)
    {
        m = (l + r + 1) / 2;
        cout << m << endl;
        cin >> s;
        if (s == "<") r = m - 1;
        else l = m;
    }
    cout << "! " << l << endl;
}

