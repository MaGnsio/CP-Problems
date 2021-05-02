//https://codeforces.com/group/aDFQm4ed6d/contest/279956/problem/E
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

bool is_vowel (char x)
{
    if (x == 'A' || x == 'E' || x == 'I' || x == 'O' || x == 'U' || x == 'Y') return true;
    if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u' || x == 'y') return true;
    return false;
}
bool is_letter (char x)
{
    if (x >= 'a' && x <= 'z') return true;
    if (x >= 'A' && x <= 'Z') return true;
    return false;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    char x;
    string s;
    getline (cin, s);
    for (int i = s.size () - 1; i >= 0; --i)
    {
        if (is_letter (s[i]))
        {
            x = s[i];
            break;
        }
    }
    cout << (is_vowel (x) ? "YES" : "NO");
}

