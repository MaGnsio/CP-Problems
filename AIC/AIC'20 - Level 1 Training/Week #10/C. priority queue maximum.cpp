//https://codeforces.com/group/Rv2Qzg0DgK/contest/290492/problem/C
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
    ll n, x;
    string s;
    priority_queue<ll> pq;
    cin >> n;
    while (n--)
    {
        cin >> s;
        if (s == "push")
        {
            cin >> x;
            pq.push (x);
        }
        if (s == "pop") pq.pop ();
        if (s == "top") cout << pq.top () << "\n";
    }
}

