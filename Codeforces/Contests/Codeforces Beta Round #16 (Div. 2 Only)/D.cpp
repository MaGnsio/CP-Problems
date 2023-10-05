/**
 *    author:  MaGnsi0
 *    created: 25.12.2021 23:51:43
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    cin.get();
    for (int i = 0; i < n; ++i) {
        string s;
        getline(cin, s);
        int h = (stoi(s.substr(1, 2)) + 12 * (s[7] == 'p')) % 24;
        if (h == 12) {
            h = 0;
        } else if (h == 0) {
            h = 12;
        }
        int m = stoi(s.substr(4, 2));
        a[i] = 60 * h + m;
    }
    int res = 0;
    auto ok = [&](int i, int j) {
        for (int k = i; k <= j; ) {
            int l = k + 1;
            while (l <= j && a[l] == a[k]) {
                l++;
            }
            if (l - k > 10) {
                return false;
            }
            k = l;
        }
        return true;
    };
    for (int i = 0; i < n; ) {
        int j = i + 1;
        while (j < n && a[j] >= a[j - 1] && ok(i, j)) {
            j++;
        }
        i = j;
        res++;
    }
    cout << res;
}
