/**
 *    author:  MaGnsi0
 *    created: 28.10.2023 04:05:58
**/
#include <bits/stdc++.h>

using namespace std;

string lower(string x) {
    string y = "";
    for (char c : x) {
        if (isalpha(c)) {
            y += tolower(c);
        } else {
            y += c;
        }
    }
    return y;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int m; cin >> m; cin.ignore();
    map<string, int> mp;
    for (int i = 0; i < n; ++i) {
        string s; getline(cin, s);
        stringstream sin(s);
        string in;
        while (sin >> in) {
            in = lower(in);
            mp[in] = i + 1;
        }
    }
    cin.ignore();
    vector<int> F(26), ans(m), C(n);
    for (int i = 0; i < m; ++i) {
        string s; getline(cin, s);
        stringstream sin(s);
        string in;
        while (sin >> in) {
            in = lower(in);
        }
        ans[i] = mp[in];
        if (mp[in]) { C[mp[in] - 1]++; }
    }
    string R = "";
    vector<char> mp_(n, 'X');
    for (int i = 0, j = 0; i < m; ++i) {
        if (ans[i] == 0 || C[ans[i] - 1] == 1) {
            R += 'X';
            continue;
        }
        if (char('A' + j) == 'X') { j++; }
        if (mp_[ans[i] - 1] == 'X') {
            mp_[ans[i] - 1] = char('A' + j++);
        }
        R += mp_[ans[i] - 1];
    }
    cout << R;
}
