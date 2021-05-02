//https://codeforces.com/contest/1504/problem/A
#include <bits/stdc++.h>
using namespace std;

bool is_palindrome (string s) {
    for (int i = 0; 2 * i < s.size (); ++i) {
        if (s[i] != s[s.size () - i - 1]) {
            return false;
        }
    }
    return true;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        string x = s + 'a', y = 'a' + s;
        if (!is_palindrome (x)) {
            cout << "YES\n" << x << "\n";
        }
        else if (!is_palindrome (y)) {
            cout << "YES\n" << y << "\n";
        }
        else {
            cout << "NO\n";
        }
    }
}

