//https://vjudge.net/contest/417978#problem/L
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
    string f[10] = {"", "", "2", "3", "223", "5", "53", "7", "7222", "7332"};
    ll n;
    string s, t = "";
    cin >> n >> s;
    for (auto& X : s) t += f[X - '0'];
    sort (t.begin (), t.end (), greater<char> ());
    cout << t;
}

