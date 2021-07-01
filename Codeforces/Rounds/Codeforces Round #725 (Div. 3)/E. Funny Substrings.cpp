/**
 *    author:  MaGnsi0
 *    created: 10/06/2021 16:23:58
**/
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Word {
    int len;
    int cnt;
    string s;
};

string getFirst(string s) {
    if (s.size() < 3) {
        return s;
    }
    return s.substr(0, 3);
}

string getLast(string s) {
    if (s.size() < 3) {
        return s;
    }
    return s.substr(s.size() - 3, 3);
}

int count(const string& s, const string& p) {
    int cnt = 0;
    for (int i = 0; i + p.size() <= s.size(); i++) {
        if (s.substr(i, p.size()) == p) {
            cnt++;
        }
    }
    return cnt;
}

Word merge(const Word& a, const Word& b) {
    Word c;
    c.len = a.len + b.len;
    c.s = a.s + b.s;
    c.cnt = a.cnt + b.cnt + count(getLast(a.s) + getFirst(b.s), "haha");
    if (c.s.size() >= 7) {
        c.s = getFirst(c.s) + "@" + getLast(c.s);
    }
    return c;
}

void solve() {
    int n, ans = 0;
    cin >> n;
    map<string, Word> vars;
    for (int i = 0; i < n; i++) {
        string var;
        cin >> var;
        string opr;
        cin >> opr;
        if (opr == "=") {
            string x, plus, y;
            cin >> x >> plus >> y;
            vars[var] = merge(vars[x], vars[y]);
        } else {
            string val;
            cin >> val;
            Word word;
            word.len = val.length();
            word.cnt = count(val, "haha");
            word.s = val;
            vars[var] = word;
        }
        ans = vars[var].cnt;
    }
    cout << ans << "\n";
}

int32_t main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
