//https://codeforces.com/group/aDFQm4ed6d/contest/274872/problem/E
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
    ll N, X;
    cin >> N;
    while (N--)
    {
        cin >> X;
        if (X) return cout << "HARD", 0;
    }
    cout << "EASY";
}

