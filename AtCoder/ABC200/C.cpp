//https://atcoder.jp/contests/abc200/tasks/abc200_c
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N;
    cin >> N;
    vector<long long> V(200, 0);
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        V[x % 200]++;
    }
    long long cnt = 0;
    for (int i = 0; i < 200; ++i) {
        cnt += V[i] * (V[i] - 1) / 2;
    }
    cout << cnt;
}
