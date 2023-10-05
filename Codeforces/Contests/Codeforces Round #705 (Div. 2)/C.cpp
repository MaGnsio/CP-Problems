/**
 *    author:  MaGnsi0
 *    created: 15.12.2021 23:14:48
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k >> s;
        if (n % k) {
            cout << "-1\n";
            continue;
        }
        vector<int> f(26, 0);
        for (int i = 0; i < n; ++i) {
            f[s[i] - 'a']++;
        }
        auto calc = [&](vector<int> a) {
            int sum = 0;
            for (int i = 0; i < 26; ++i) {
                sum += (k - a[i] % k) % k;
            }
            return sum;
        };
        if (calc(f) == 0) {
            cout << s << "\n";
            continue;
        }
        for (int i = n - 1; i >= 0; --i) {
            f[s[i] - 'a']--;
            for (int j = s[i] - 'a' + 1; j < 26; ++j) {
                vector<int> temp = f;
                temp[j]++;
                if ((n - i - 1 >= calc(temp)) && ((n - i - 1 - calc(temp)) % k == 0)) {
                    string res = s;
                    res[i] = char('a' + j);
                    int z = n - 1;
                    for (int x = 25; x >= 0; --x) {
                        for (int y = 0; y < (k - temp[x] % k) % k; ++y) {
                            res[z--] = char('a' + x);
                        }
                    }
                    while (z != i) {
                        res[z--] = 'a';
                    }
                    cout << res << "\n";
                    goto finish;
                }
            }
        }
        finish:;
    }
}
