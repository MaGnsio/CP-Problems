//https://atcoder.jp/contests/abc195/tasks/abc195_b
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
    int a, b, w;
    cin >> a >> b >> w;
    int Min = (w * 1000 + b - 1) / b, Max = (w * 1000) / a;
    if (Min > Max) cout << "UNSATISFIABLE";
    else cout << Min << " " << Max;
}
