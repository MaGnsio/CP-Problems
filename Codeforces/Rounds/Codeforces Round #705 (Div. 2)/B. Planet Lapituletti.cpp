//https://codeforces.com/contest/1493/problem/B
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int rt (char a, char b) {return ((a - '0') * 10 + (b - '0'));}
bool chk (int a, int b)
{
    char f[2];
    for (int i = 1; i <= 2; ++i)
    {
        //0 <-> 0, 1 <-> 1, 2 <-> 5, 8 <-> 8
        if (a % 10 == 0) f[i - 1] = '0';
        else if (a % 10 == 1) f[i - 1] = '1';
        else if (a % 10 == 2) f[i - 1] = '5';
        else if (a % 10 == 5) f[i - 1] = '2';
        else if (a % 10 == 8) f[i - 1] = '8';
        else return false;
        a /= 10;
    }
    int temp = rt (f[0], f[1]);
    return (temp < b);
}
ll bt (ll a, ll b, ll c)
{
    for (int i = a; i < b; ++i) if (chk (i, c)) return i;
    return 0;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--)
    {
        int h, m;
        bool c = false;
        string t;
        cin >> h >> m >> t;
        int x = rt (t[0], t[1]), y = rt (t[3], t[4]);
        int a = bt (x, h, m);
        int b = (x == a ? bt (y, m, h) : 0);
        a = (x == a && y && !b ? bt ((x + 1) % h, h, m) : a);
        cout << setw (2) << setfill ('0') << a << ":" << setw (2) << setfill ('0') << b << "\n";
    }
}

