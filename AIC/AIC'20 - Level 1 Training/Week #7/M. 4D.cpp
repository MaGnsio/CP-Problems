//https://codeforces.com/group/Rv2Qzg0DgK/contest/285699/problem/M
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

struct item
{
    string s;
    ll x, y, z, w, idx;
    ll sum = 0;
};
bool comp (item a, item b)
{
    return (a.sum < b.sum) || (a.sum == b.sum && a.idx > b.idx);
}
ll sll (string s)
{
    ll x = 0;
    for (auto elem : s) x += elem;
    return x;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll n, idx = 0;
    cin >> n;
    item a[n];
    for (auto& elem : a)
    {
        cin >> elem.s >> elem.x >> elem.y >> elem.z >> elem.w;
        elem.idx = idx, elem.sum = sll (elem.s) + elem.y + elem.w, idx++;
    }
    sort (a, a + n, comp);
    for (auto& elem : a) cout << elem.s << " " << elem.x << " " << elem.y << " " << elem.z << " " << elem.w << "\n";
}

