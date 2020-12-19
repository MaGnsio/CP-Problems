//https://codeforces.com/group/Rv2Qzg0DgK/contest/287283/problem/O
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
    int n, x, id;
    queue<int> q;
    cin >> n;
    while (n--)
    {
        cin >> x >> id;
        if (x == 1) q.push (id);
        else
        {
            if (q.front () == id) cout << "Yes\n";
            else cout << "No\n";
            q.pop ();
        }
    }
}

