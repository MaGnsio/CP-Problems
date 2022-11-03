//https://atcoder.jp/contests/abc183/tasks/abc183_c
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
const ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n, k, cnt = 0;
    cin >> n >> k;
    vector<vector<int>> T (n, vector<int> (n));
    for (auto& x : T) {
        for (auto& y : x) {
            cin >> y;
        }
    }
    vector<int> idx (n);
    iota (idx.begin (), idx.end (), 0);
    do {
        int t = 0;
        for (int i = 0; i < n; ++i) {
            t += T[idx[i]][idx[(i + 1) % n]];
        }
        if (t == k) cnt++;
    } while (next_permutation (idx.begin () + 1, idx.end ()));
    cout << cnt;
}

