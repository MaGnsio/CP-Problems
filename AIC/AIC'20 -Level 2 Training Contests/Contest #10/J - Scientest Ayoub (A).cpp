//https://vjudge.net/contest/436257#problem/J
#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N; 
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cout << (1 << i) << " ";
    }
}

