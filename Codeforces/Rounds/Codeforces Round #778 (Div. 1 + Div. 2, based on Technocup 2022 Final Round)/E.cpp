/**
 *    author:  MaGnsi0
 *    created: 21.07.2023 17:02:47
**/
#include <bits/stdc++.h>

using namespace std;

const int N = 320, M = 2e8, offset = 1e8;

int F(vector<int> a) {
    int n = (int)a.size(), ans = n;
    vector<int> cnt(M, 0);
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1, k = 0; j < n && k < N; ++j, ++k) {
            if ((a[j] - a[i]) % (j - i)) { continue; }
            int x = (a[j] - a[i]) / (j - i);
            cnt[x + offset]++;
            ans = min(ans, n - (cnt[x + offset] + 1));
        }
        for (int j = i - 1, k = 0; j >= 0 && k < N; --j, ++k) {
            if ((a[i] - a[j]) % (i - j)) { continue; }
            int x = (a[i] - a[j]) / (i - j);
            cnt[x + offset]++;
            ans = min(ans, n - (cnt[x + offset] + 1));
        }
        for (int j = i + 1, k = 0; j < n && k < N; ++j, ++k) {
            if ((a[j] - a[i]) % (j - i)) { continue; }
            int x = (a[j] - a[i]) / (j - i);
            cnt[x + offset]--;
        }
        for (int j = i - 1, k = 0; j >= 0 && k < N; --j, ++k) {
            if ((a[i] - a[j]) % (i - j)) { continue; }
            int x = (a[i] - a[j]) / (i - j);
            cnt[x + offset]--;
        }
    }
    for (int x = 0; x < N; ++x) {
        for (int i = 0; i < n; ++i) {
            cnt[a[i] - i * x + offset]++;
            ans = min(ans, n - cnt[a[i] - i * x + offset]);
        }
        for (int i = 0; i < n; ++i) {
            cnt[a[i] - i * x + offset]--;
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int ans = F(a);
    reverse(a.begin(), a.end());
    ans = min(ans, F(a));
    cout << ans;
}
