/**
 *    author:  MaGnsi0
 *    created: 04/06/2021 18:58:16
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    string s;
    cin >> s;
    int a = count(s.begin(), s.end(), 'a') + count(s.begin(), s.end(), 'A');
    int t = count(s.begin(), s.end(), 't') + count(s.begin(), s.end(), 'T');
    int y = count(s.begin(), s.end(), 'y') + count(s.begin(), s.end(), 'Y');
    int p = count(s.begin(), s.end(), 'p') + count(s.begin(), s.end(), 'P');
    int i = count(s.begin(), s.end(), 'i') + count(s.begin(), s.end(), 'I');
    int c = count(s.begin(), s.end(), 'c') + count(s.begin(), s.end(), 'C');
    int l = count(s.begin(), s.end(), 'l') + count(s.begin(), s.end(), 'L');
    if (a >= 2 && t && y && p && i && c && l) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
