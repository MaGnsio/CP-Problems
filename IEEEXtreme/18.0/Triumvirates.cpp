/**
 *    author:  MaGnsi0
 *    created: 26.10.2024 19:29:37
**/
#include <bits/stdc++.h>

using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 1e5 + 1;

int n;
vector<int> I(N);
pair<int, int> p[N];

int64_t D(int i, int j) {
    int64_t dx = p[i].first - p[j].first;
    int64_t dy = p[i].second - p[j].second;
    return dx * dx + dy * dy;
};
int64_t F(int i, int j, int k) {
    vector<int64_t> Ds = {D(i, j), D(i, k), D(j, k)};
    sort(Ds.begin(), Ds.end());
    return Ds[2] - Ds[0];
};

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    iota(I.begin(), I.end(), 0);
    for (int i = 0; i < n; ++i) {
        cin >> p[i].first >> p[i].second;
    }
    pair<int64_t, vector<int>> ans = {INT64_MAX, vector<int>()};
    for (int iterions = 0; iterions < 500; ++iterions) {
        shuffle(I.begin(), I.begin() + n, rng);
        int64_t val = 0;
        for (int i = 0; i < n; i += 3) {
            val += F(I[i], I[i + 1], I[i + 2]);
        }
        ans = min(ans, make_pair(val, I));
    }
    for (int i = 0; i < n; i += 3) {
        cout << ans.second[i] << " " << ans.second[i + 1] << " " << ans.second[i + 2] << "\n";
    }
}
