/**
 *    author:  MaGnsi0
 *    created: 06/10/2021 01:24:10
**/
#include <bits/stdc++.h>
using namespace std;


/*
 * order_of_key(k) : Number of items strictly smaller than k.
 * find_by_order(k) : K-th element in a set (counting from zero).
 */
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;



int main() {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    vector<int> res(n + 1, 0);
    ordered_set<int> b;
    for (int i = 0; i < n; ++i) {
        int x = a[i].first, j = a[i].second;
        int l = b.order_of_key(j);
        if (l == 0) {
            res[0]++, res[j]--;
        } else {
            int s = *(b.find_by_order(l - 1));
            int d = (j - s - 1) / 2;
            s = j - d;
            res[s]++, res[j]--;
        }
        int r = b.size() - l;
        if (r == 0) {
            res[j + 1]++, res[n]--;
        } else {
            int e = *(b.find_by_order(l));
            int d = (e - j - 1) / 2;
            e = j + d;
            res[j + 1]++, res[e + 1]--;
        }
        b.insert(j);
    }
    for (int i = 1; i <= n; ++i) {
        res[i] += res[i - 1];
    }
    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
}
