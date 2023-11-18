/**
 *    author:  MaGnsi0
 *    created: 28.10.2023 02:04:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T;
    while (T--) {
        int shift; cin >> shift; cin.ignore();
        string s, t; getline(cin, s);
        stringstream sin(s);
        bool is_plan = false;
        vector<string> a;
        while (sin >> t) {
            a.push_back(t);
            is_plan |= t == "the";
        }
        vector<string> b;
        for (string x : a) {
            t = "";
            for (char c : x) {
                if (is_plan) {
                    t += char('a' + ((c - 'a' - shift) % 26 + 26) % 26);
                } else {
                    t += char('a' + (c - 'a' + shift) % 26);
                }
            }
            b.push_back(t);
        }
        for (string x : b) {
            cout << x << " ";
        }
        cout << "\n";
    }
}
