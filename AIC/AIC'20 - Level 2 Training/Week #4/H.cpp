//https://vjudge.net/contest/433102#problem/H
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome (string s) {
    for (int i = 0; i < s.size () / 2; ++i) {
        if (s[i] != s[s.size () - i - 1]) {
            return false;
        }
    }
    return true;
}

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s, p = "";
    cin >> s;
    for (int mask = 1; mask < (1 << s.size ()); ++mask) {
        string t = "";
        for (int j = 0; j < s.size (); ++j) {
            if ((1 << j) & mask) {
                t.push_back (s[j]);
            }
        }
        if (isPalindrome (t) && t > p) {
            p = t;
        }
    }
    cout << p;
}

