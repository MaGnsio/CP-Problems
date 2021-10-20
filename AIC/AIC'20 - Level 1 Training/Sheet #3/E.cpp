//https://codeforces.com/group/Rv2Qzg0DgK/contest/272491/problem/E
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
	int n;
	cin >> n;
	vector<int> v(n);
	for (auto& elem : v) cin >> elem;
	int mi = *(min_element (v.begin (), v.end ()));
	int idx = distance (v.begin (), find (v.begin (), v.end (), mi));
	cout << mi << " " << idx + 1;
}
