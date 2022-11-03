//https://atcoder.jp/contests/abc203/tasks/abc203_b
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, K, sum = 0;
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            sum += i * 100 + j;
        }
    }
    cout << sum;
}
