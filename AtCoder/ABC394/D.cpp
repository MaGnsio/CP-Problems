/**
 *    author:  MaGnsi0
 *    created: 22.02.2025 14:06:31
**/
#include <bits/stdc++.h>

using namespace std;

bool is_open(char c) {
    return c == '(' || c == '[' || c == '<';
}

bool is_match(char c1, char c2) {
    string s = ""; s += c1; s += c2;
    return s == "()" || s == "[]" || s == "<>";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    int n = (int)s.size();
    stack<char> opens;
    for (int i = 0; i < n; ++i) {
        if (is_open(s[i])) {
            opens.push(s[i]);
        } else {
            if (opens.empty() || !is_match(opens.top(), s[i])) {
                cout << "No";
                return 0;
            }
            opens.pop();
        }
    }
    cout << (opens.empty() ? "Yes" : "No");
}
