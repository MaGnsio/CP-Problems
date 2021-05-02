//https://vjudge.net/contest/435128#problem/I
#include <bits/stdc++.h>
using namespace std;

void solve(int& N, int& W, vector<pair<int, int>>& V, int& maxi, int total = 0, int idx = 0) {
    if (idx == N) {
        maxi = max(maxi, total);
        return;
    }
    if (V[idx].first > W) {
        maxi = max(maxi, total);
        return;
    }
    solve(N, W, V, maxi, total, idx + 1);
    W -= V[idx].first;
    solve(N, W, V, maxi, total + V[idx].second, idx + 1);
    W += V[idx].first;
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, W, maxi = INT_MIN;
    cin >> N >> W;
    vector<pair<int, int>> V(N);
    for (auto& x : V) {
        cin >> x.first >> x.second;
    }
    sort(V.begin(), V.end());
    solve(N, W, V, maxi);
    cout << maxi;
}

