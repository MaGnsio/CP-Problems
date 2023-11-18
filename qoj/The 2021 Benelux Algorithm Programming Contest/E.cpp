/**
 *    author:  MaGnsi0
 *    created: 05.10.2023 18:02:01
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    vector<set<int>> a(4), b(4);
    for (int i = 0; i < n; ++i) {
        if (s[i] == 'A') { a[0].insert(i); }
        if (s[i] == 'C') { a[1].insert(i); }
        if (s[i] == 'G') { a[2].insert(i); }
        if (s[i] == 'T') { a[3].insert(i); }
        if (t[i] == 'A') { b[0].insert(i); }
        if (t[i] == 'C') { b[1].insert(i); }
        if (t[i] == 'G') { b[2].insert(i); }
        if (t[i] == 'T') { b[3].insert(i); }
    }
    for (int i = 0; i < 4; ++i) {
        a[i].insert(n);
        b[i].insert(n);
    }
    int i = 0, j = 0;
    string ans = "";
    while (i < n && j < n) {
        char add = '*';
        int remaining = -1;
        {
            int x = *a[0].lower_bound(i);
            int y = *b[0].lower_bound(j);
            if (x < n && y < n && 2 * n - (x + y + 2) > remaining) {
                add = 'A';
                remaining = 2 * n - (x + y + 2);
            }
        }
        {
            int x = *a[1].lower_bound(i);
            int y = *b[1].lower_bound(j);
            if (x < n && y < n && 2 * n - (x + y + 2) > remaining) {
                add = 'C';
                remaining = 2 * n - (x + y + 2);
            }
        }
        {
            int x = *a[2].lower_bound(i);
            int y = *b[2].lower_bound(j);
            if (x < n && y < n && 2 * n - (x + y + 2) > remaining) {
                add = 'G';
                remaining = 2 * n - (x + y + 2);
            }
        }
        {
            int x = *a[3].lower_bound(i);
            int y = *b[3].lower_bound(j);
            if (x < n && y < n && 2 * n - (x + y + 2) > remaining) {
                add = 'T';
                remaining = 2 * n - (x + y + 2);
            }
        }
        if (remaining == -1) { break; }
        ans += add;
        if (add == 'A') {
            i = *a[0].lower_bound(i) + 1;
            j = *b[0].lower_bound(j) + 1;
        }
        if (add == 'C') {
            i = *a[1].lower_bound(i) + 1;
            j = *b[1].lower_bound(j) + 1;
        }
        if (add == 'G') {
            i = *a[2].lower_bound(i) + 1;
            j = *b[2].lower_bound(j) + 1;
        }
        if (add == 'T') {
            i = *a[3].lower_bound(i) + 1;
            j = *b[3].lower_bound(j) + 1;
        }
    }
    cout << ans;
}
