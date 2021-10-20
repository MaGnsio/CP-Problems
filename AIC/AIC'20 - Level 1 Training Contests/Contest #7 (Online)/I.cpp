//https://codeforces.com/group/aDFQm4ed6d/contest/275835/problem/I
#include <bits/stdc++.h>
using namespace std;
#define F first 
#define S second
typedef long long ll;
typedef long double ld;
ll mod = 1e9 + 7;

int main ()
{
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    ll N, M;
    cin >> N >> M;
    ll A[N][M];
    vector<ll> S;
    for (auto& X : A) for (auto& Y : X) cin >> Y;
    ll left = 0, right = M - 1, top = 0, bottom = N - 1;
    while (S.size () < N * M)
    {
        for (ll i = left; i <= right; ++i) S.push_back (A[top][i]);
        if (S.size () == N * M) break;
        top++;
        for (ll i = top; i <= bottom; ++i) S.push_back (A[i][right]);
        if (S.size () == N * M) break;
        right--;
        for (ll i = right; i >= left; --i) S.push_back (A[bottom][i]);
        if (S.size () == N * M) break;
        bottom--;
        for (ll i = bottom; i >= top; --i) S.push_back (A[i][left]);
        if (S.size () == N * M) break;
        left++;
    }
    for (auto& X : S) cout << X << " ";
}

