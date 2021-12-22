/**
 *    author:  MaGnsi0
 *    created: 11.12.2021 19:39:28
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s;
    cin >> s;
    vector<int> ones;
    for (int i = 0; i < (int)s.size(); ++i) {
        if (s[i] == '0' || (i && s[i - 1] == '1')) {
            continue;
        }
        int cnt = 0;
        for (int j = i; j < (int)s.size(); ++j) {
            if (s[j] == '1') {
                cnt++;
            } else {
                break;
            }
        }
        ones.push_back(cnt);
    }
    sort(ones.begin(), ones.end());
    int res = 0;
    for (int i = 0; i < (int)ones.size() - 1; ++i) {
        res += ones[i];
    }
    cout << res << "\n";
}
