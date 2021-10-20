/**
 *    author:  MaGnsi0
 *    created: 16/07/2021 13:24:55
**/
#include <bits/stdc++.h>
using namespace std;

bool good(vector<int> v, int mid, int k) {
    int curw = 0, a = 0;
    for (auto& x : v) {
        if (x > mid) {
            return false;
        }
        if (curw + x > mid) {
            a++;
            curw = x;
        } else {
            curw += x;
        }
        if (a > k) {
            return false;
        }
    }
    a += (curw != 0);
    return (a <= k);
}

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int k;
    cin >> k;
    string s;
    cin.ignore();
    getline(cin, s);
    vector<int> v;
    for (int i = 0, curl = 1; i < s.size(); ++i) {
        if (s[i] == '-' || s[i] == ' ' || i == s.size() - 1) {
            v.push_back(curl);
            curl = 1;
        } else {
            curl++;
        }
    }
    int l = 1, r = s.size(), ans;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (good(v, mid, k)) {
            r = mid - 1;
            ans = mid;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}
