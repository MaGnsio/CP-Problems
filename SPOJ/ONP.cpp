/**
 *    author:  MaGnsi0
 *    created: 24.01.2022 04:49:43
**/
#include <bits/stdc++.h>

using namespace std;

string shunting_yard(string s) {
    string t = "";
    stack<char> op;
    for (int i = 0; i < (int)s.size(); ++i) {
        if ('a' <= s[i] && s[i] <= 'z') {
            t += s[i];
        } else if (s[i] != ')') {
            op.push(s[i]);
        } else {
            while (op.top() != '(') {
                t += op.top();
                op.pop();
            }
            op.pop();
        }
    }
    return t;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;
        cout << shunting_yard(s) << "\n";
    }
}
