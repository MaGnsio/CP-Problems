/**
 *    author:  MaGnsi0
 *    created: 03.01.2023 18:45:15
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    function<int(int, string)> ask = [](int j, string s) {
        cout << "? " << j + 1 << " " << s << endl;
        int ans;
        cin >> ans;
        return ans;
    };
    int n;
    cin >> n;
    int cur = 0;
    string all(n, '1');
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        all[i] = '0';
        cnt[i] = ask(i, all);
        all[i] = '1';
    }
    vector<int> I(n);
    iota(I.begin(), I.end(), 0);
    sort(I.begin(), I.end(), [&](int i, int j) {
            return cnt[i] > cnt[j];
        });
    string ans(n, '0');
    ans[I[0]] = '1';
    for (int i = 1; i < n; ++i) {
        int x = ask(I[i], ans);
        if (x) {
            for (int j = 0; j <= i; ++j) {
                ans[I[j]] = '1';
            }
        }
    }
    cout << "! " << ans << endl;
}
