//https://codeforces.com/contest/1512/problem/C
#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        string s;
        cin >> a >> b >> s;
        int n = s.size ();
        bool chk = true;
        for (auto& c : s) {
            if (c == '0') {
                if (a > 0) a--;
                else chk = false;
            }
            if (c == '1') {
                if (b > 0) b--;
                else chk = false;
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != '?' && s[n - i - 1] != '?') {
                if (s[i] != s[n - i - 1]) {
                    chk = false;
                }
                continue;
            }
            if (s[i] == '?' && s[n - i - 1] != '?') {
                if (s[n - i - 1] == '0') {
                    if (a >= 1) {
                        s[i] = '0';
                        a--;
                    }
                    else {
                        chk = false;
                    }
                }
                else {
                    if (b >= 1) {
                        s[i] = '1';
                        b--;
                    }
                    else {
                        chk = false;
                    }
                }
            }
            else if (s[i] != '?' && s[n - i - 1] == '?') {
                if (s[i] == '0') {
                    if (a >= 1) {
                        s[n - i - 1] = '0';
                        a--;
                    }
                    else {
                        chk = false;
                    }
                }
                else {
                    if (b >= 1) {
                        s[n - i - 1] = '1';
                        b--;
                    }
                    else {
                        chk = false;
                    }
                }
            }
        }
        for (int i = 0; i < n / 2; ++i) {
            if (s[i] != '?' && s[n - i - 1] != '?') {
                if (s[i] != s[n - i - 1]) {
                    chk = false;
                }
                continue;
            }
            if (s[i] == '?' && s[n - i - 1] == '?') {
                if (a >= 2) {
                    s[i] = s[n - i - 1] = '0';
                    a -= 2;
                }
                else if (b >= 2) {
                    s[i] = s[n - i - 1] = '1';
                    b -= 2;
                }
                else {
                    chk = false;
                }
            }
        }
        if (s[n / 2] == '?') {
            if (a > 0) {
                s[n / 2] = '0';
                a--;
            }
            else if (b > 0) {
                s[n / 2] = '1';
                b--;
            }
            else {
                chk = false;
            }
        }
        if (chk && a == 0 && b == 0)
            cout << s << "\n";
        else
            cout << -1 << "\n";
    }
}

