//https://codeforces.com/group/aDFQm4ed6d/contest/296501/problem/A
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

char to_lower (char c)
{
    if (c >= 'a' && c <= 'z') return c;
    else return char (c + 32);
}

bool is_vowel (char c)
{
    if (c == 'A' || c == 'O' || c == 'Y' || c == 'E' || c == 'U' || c == 'I') return true;
    if (c == 'a' || c == 'o' || c == 'y' || c == 'e' || c == 'u' || c == 'i') return true;
    return false;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s;
    cin >> s;
    for (auto& x : s)
    {
        if (is_vowel (x)) continue;
        cout << "." << to_lower (x);
    }
}

