/**
 *    author:  MaGnsi0
 *    created: 30/09/2021 00:42:58
**/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 6;

bool first_system(string s) {
    int a = 0, b = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
        if ('A' <= s[i] && s[i] <= 'Z') {
            if (a) {
                b = 1;
            } else {
                a = 1;
            }
            while ('A' <= s[i] && s[i] <= 'Z' && i < (int)s.size()) {
                i++;
            }
            i--;
        }
    }
    return (a && b);
}

void first_to_second(string s) {
    int i = 1, r = 0, c = 0;
    string sc = "";
    for (; s[i] != 'C'; ++i) {
        r = (r * 10) + (s[i] - '0');
    }
    for (++i; i < (int)s.size(); ++i) {
        c = (c * 10) + (s[i] - '0');
    }
    while (c > 0) {
        sc = (char)('A' + (c - 1) % 26) + sc;
        if (c % 26 == 0) {
            c -= 26;
        }
        c /= 26;
    }
    cout << sc << r << "\n";
}

void second_to_first(string s) {
    int i = 0, r = 0, c = 0;
    for (; isalpha(s[i]); ++i) {
        c = (c * 26) + (s[i] - 'A' + 1);
    }
    for (; i < (int)s.size(); ++i) {
        r = (r * 10) + (s[i] - '0');
    }
    cout << "R" << r << "C" << c << "\n";
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        if (first_system(s)) {
            first_to_second(s);
        } else {
            second_to_first(s);
        }
    }
}
