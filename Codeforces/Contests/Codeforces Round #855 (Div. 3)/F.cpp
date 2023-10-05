/**
 *    author:  MaGnsi0
 *    created: 15.03.2023 02:56:45
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
    }
    vector<int> a(n, 0), b(n, 0);
    for (int i = 0; i < n; ++i) {
        vector<int> f(26, 0);
        for (char c : words[i]) {
            f[c - 'a']++;
        }
        for (int j = 0; j < 26; ++j) {
            if (f[j] & 1) {
                a[i] |= (1 << j);
            }
            if (f[j]) {
                b[i] |= (1 << j);
            }
        }
    }
    int64_t ans = 0;
    vector<map<int, int>> dont_have(26);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            if ((1 << j) & b[i]) {
                continue;
            }
            int x = a[i] ^ ((1 << 26) - 1) ^ (1 << j);
            if (dont_have[j].count(x)) {
                ans += dont_have[j][x];
            }
        }
        for (int j = 0; j < 26; ++j) {
            if (!((1 << j) & b[i])) {
                dont_have[j][a[i]]++;
            }
        }
    }
    cout << ans;
}
