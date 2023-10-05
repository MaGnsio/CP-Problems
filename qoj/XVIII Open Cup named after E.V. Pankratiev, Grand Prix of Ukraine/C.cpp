/**
 *    author:  MaGnsi0
 *    created: 30.09.2023 16:30:56
**/
#pragma GCC optimize("O3")
#pragma GCC target ("avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

vector<string> C;

void buildC() {
    vector<int> power(10, 1);
    for (int i = 1; i < 10; ++i) {
        power[i] = 3 * power[i - 1];
    }
    for (int s = 1; s <= 9; ++s) {
        for (int mask = 0; mask < power[s]; ++mask) {
            int val = mask;
            string c = "";
            for (int i = 0; i < s; ++i) {
                int x = val % 3;
                if (x == 0) { c += "a"; }
                if (x == 1) { c += "b"; }
                if (x == 2) { c += "c"; }
                val /= 3;
            }
            C.push_back(c);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    buildC();
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (string c : C) {
        int l = 0, i = 0, j = 0, m = (int)c.size();
        if (m > n) { continue; }
        while (j < n) {
            if (s[j] == c[i]) {
                l++, i = (i == m - 1 ? 0 : i + 1);
            }
            j++;
        }
        l -= l % m;
        ans = max(ans, (l * l) / m);
    }
    cout << ans << "\n";
}
