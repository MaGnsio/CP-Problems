/**
 *    author:  MaGnsi0
 *    created: 12.09.2023 03:30:29
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<string> S(n);
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    sort(S.begin(), S.end(), [](string x, string y) {
            return (int)x.size() > (int)y.size();
        });
    function<bool(string, string)> Good = [](string x, string y) {
        int n = (int)x.size(), m = (int)y.size(), k = 0;
        for (int i = 0; i < n && k < m; ++i) {
            k += (x[i] == y[k]);
        }
        return k == m;
    };
    vector<string> a(1, s), b(1, s), c;
    for (int i = 0; i < n; ++i) {
        bool X = Good(a.back(), S[i]);
        bool Y = Good(b.back(), S[i]);
        bool Z = (c.empty() ? true : Good(c.back(), S[i]));
        if (X && Y) {
            if (Z) {
                c.push_back(S[i]);
            } else {
                a.insert(a.end(), c.begin(), c.end());
                b.push_back(S[i]); c.clear();
            }
        } else if (X) {
            if (Z) {
                a.insert(a.end(), c.begin(), c.end());
                a.push_back(S[i]); c.clear();
            } else {
                b.insert(b.end(), c.begin(), c.end());
                a.push_back(S[i]); c.clear();
            }
        } else if (Y) {
            if (Z) {
                b.insert(b.end(), c.begin(), c.end());
                b.push_back(S[i]); c.clear();
            } else {
                a.insert(a.end(), c.begin(), c.end());
                b.push_back(S[i]); c.clear();
            }
        } else {
            cout << "impossible";
            return 0;
        }
    }
    a.insert(a.end(), c.begin(), c.end());
    c.clear();
    int m = (int)a.size(), k = (int)b.size();
    cout << m - 1 << " " << k - 1 << "\n";
    for (int i = m - 1; i; --i) {
        cout << a[i] << "\n";
    }
    for (int i = k - 1; i; --i) {
        cout << b[i] << "\n";
    }
}
