//https://atcoder.jp/contests/abc203/tasks/abc203_c
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, K;
    cin >> N >> K;
    vector<pair<long long, long long>> V(N);
    for (int i = 0; i < N; ++i) {
        cin >> V[i].first >> V[i].second;
    }
    sort(V.begin(), V.end());
    long long currV = 0, currM = K;
    for (int i = 0; i < N; ++i) {
        if (V[i].first - currV <= currM) {
            currM = currM - (V[i].first - currV) + V[i].second;
            currV = V[i].first;
        } else {
            cout << currV + currM;
            return 0;
        }
    }
    cout << currV + currM;
}
