//https://atcoder.jp/contests/abc200/tasks/abc200_b
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    long long N;
    int K;
    cin >> N >> K;
    while (K--) {
        if (N % 200 == 0) {
            N /= 200;
        } else {
            N = N * 1000 + 200;
        }
    }
    cout << N;
}
