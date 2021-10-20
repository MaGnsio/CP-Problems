/**
 *    author:  MaGnsi0
 *    created: 31/07/2021 09:48:47
**/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, m, k;
    cin >> n >> m >> k;
    k %= 26;
    string s = "";
    for (int i = 0; i < 26; ++i) {
        s += char('a' + i);
    }
    string t = s.substr(k, 26 - k) + s.substr(0, k);
    vector<int> f1(26, 0), f2(26, 0);
    for (int i = 0; i < n; ++i) {
        string x;
        cin >> x;
        for (auto& c : x) {
            f1[c - 'a']++;
        }
    }
    for (int i = 0; i < m; ++i) {
        string x;
        cin >> x;
        for (auto& c : x) {
            c = t[c - 'a'];
            f2[c - 'a']++;
        }
    }
    for (int i = 0; i < 26; ++i) {
        if (f1[i] >= f2[i]) {
            continue;
        }
        cout << "It is gonna be daijoubu.";
        return 0;
    }
    cout << "Make her kokoro go doki-doki!";
}
