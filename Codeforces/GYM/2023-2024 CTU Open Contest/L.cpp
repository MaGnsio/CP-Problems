/**
 *    author:  MaGnsi0
 *    created: 25.01.2024 19:42:20
**/
#include <bits/stdc++.h>

using namespace std;

string generate(string s, int automaton) {
    int n = (int)s.size();
    s = "0" + s + "0";
    string t = "";
    for (int i = 1; i <= n; ++i) {
        int c = 0;
        if (s[i - 1] == 'X') { c |= 4; }
        if (s[i] == 'X') { c |= 2; }
        if (s[i + 1] == 'X') { c |= 1; }
        t += ((automaton >> c & 1) ? "X" : ".");
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int automaton; cin >> automaton;
    int k; cin >> k;
    string s; cin >> s;
    for (int i = 0; i < k; ++i) {
        s = generate(s, automaton);
        cout << s << "\n";
    }
}
