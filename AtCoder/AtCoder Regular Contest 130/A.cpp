/**
 *    author:  MaGnsi0
 *    created: 16.12.2021 19:07:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    string s;
    cin >> n >> s;
    vector<long long> a;
    for (int i = 0; i < n; ++i) {
        int j = i;
        while (j < n && s[i] == s[j]) {
            j++;
        }
        a.push_back(j - i);
        i = j - 1;
    }
    long long res = 0;
    for (int i = 0; i < (int)a.size(); ++i) {
        res += a[i] * (a[i] - 1) / 2;
    }
    cout << res;
}
