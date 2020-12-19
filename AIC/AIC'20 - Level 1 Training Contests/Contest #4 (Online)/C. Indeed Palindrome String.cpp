//https://codeforces.com/group/aDFQm4ed6d/contest/273591/problem/C
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
    ll freq[26] = {};
    string s;
    cin >> s;
    for (auto& elem : s) freq[elem - 'a']++;
    cout << s.size () - *max_element (freq, freq + 26);
}

