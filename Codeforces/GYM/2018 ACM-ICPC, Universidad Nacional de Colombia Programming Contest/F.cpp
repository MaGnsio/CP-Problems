/**
 *    author:  MaGnsi0
 *    created: 09.11.2021 13:04:21
**/
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n), b(26);
    vector<string> input1(n), input2(n), input3(n);
    for (int i = 0; i < 26; ++i) {
        b[i].second = i;
    }
    for (int i = 0; i < n; ++i) {
        cin >> input1[i] >> input2[i] >> input3[i];
        int f[26] = {};
        for (auto &item : input1[i]){
            f[item - 'A']++;
        }
        for (auto &item : input2[i]){
            f[item - 'A']++;
        }
        for (auto &item : input3[i]){
            f[item - 'A']++;
        }
        int mx = *max_element(f, f + 26);
        a[i] = {count(f, f + 26, mx) ,i};
        for (int i = 0; i < 26; ++i) {
            if (f[i] == mx) {
                b[i].first++;
            }
        }
    }
    int k;
    cin >> k;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> visited(n, 0), cnt(26, 0);
    auto ok = [](int i, string a, string b, string c) {
        int f[26] = {};
        for (auto &item : a){
            f[item - 'A']++;
        }
        for (auto &item : b){
            f[item - 'A']++;
        }
        for (auto &item : c){
            f[item - 'A']++;
        }
        int mx = *max_element(f, f + 26);
        return (f[i] == mx);
    };
    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!visited[a[j].second] && cnt[b[i].second] < k && ok(b[i].second, input1[a[j].second], input2[a[j].second], input3[a[j].second])) {
                visited[a[j].second] = 1;
                cnt[b[i].second]++;
            }
        }
    }
    int res = accumulate(cnt.begin(), cnt.end(), 0);
    cout << res;
}
