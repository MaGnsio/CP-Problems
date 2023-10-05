/**
 *    author:  MaGnsi0
 *    created: 17.10.2022 16:53:45
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 6;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (count(s.begin(), s.end(), '1') == n) {
        cout << s;
        return 0;
    }
    if (count(s.begin(), s.end(), '0') == n) {
        cout << 0;
        return 0;
    }
    reverse(s.begin(), s.end());
    while (s.back() == '0') {
        s.pop_back();
    }
    reverse(s.begin(), s.end());
    vector<int> a;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            a.push_back(i);
        }
    }
    for (int i = (int)a.size() - 1; i >= 0; --i) {
        a[i] -= a[0];
    }
    vector<vector<int>> b(1, vector<int>(2, -1));
    function<void(int)> add = [&](int j) {
        int cur = 0;
        for (int i = 0; i < (int)a.size(); ++i) { 
            int x = s[j + a[i]] - '0';
            if (b[cur][x] == -1) {
                b[cur][x] = (int)b.size();
                b.push_back(vector<int>(2, -1));
            }
            cur = b[cur][x];
        }
    };
    function<string()> find_max = [&]() {
        int cur = 0;
        string ans = "";
        while (true) {
            if (b[cur][0] == -1 && b[cur][1] == -1) {
                return ans;
            }
            if (b[cur][1] != -1) {
                ans += '1';
                cur = b[cur][1];
            } else {
                ans += '0';
                cur = b[cur][0];
            }
        }
    };
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            break;
        }
        if (s[i] == '1') {
            add(i);
        }
    }
    string t = find_max();
    assert(t.size() == (int)a.size());
    for (int i = 0; i < n; ++i) {
        if (s[i] == '0') {
            for (int j = 0; j < (int)a.size(); ++j) {
                s[i + a[j]] = t[j];
            }
            break;
        }
    }
    cout << s;
}
