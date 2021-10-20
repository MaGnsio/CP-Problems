//https://codeforces.com/edu/course/2/lesson/4/1/practice/contest/273169/problem/A
#include <bits/stdc++.h>
using namespace std;

template<class T, class I>
void build(vector<T>& tree, vector<T>& line, I vertex, I left, I right) {
    if (left == right) {
        tree[vertex] = line[left];
    } else {
        I mid = left + (right - left) / 2;
        build(tree, line, 2 * vertex, left, mid);
        build(tree, line, 2 * vertex + 1, mid + 1, right);
        tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1]; //query dependant
    }
}

template<class T, class I>
T query(vector<T>& tree, I vertex, I from, I to, I left, I right) {
    if (from > to) {
        return 0;
    }
    if (left == from && right == to) {
        return tree[vertex];
    }
    I mid = left + (right - left) / 2;
    return query(tree, 2 * vertex, from, min(to, mid), left, mid) + query(tree, 2 * vertex + 1, max(from, mid + 1), to, mid + 1, right); //query dependant
}

template<class T, class I>
void update(vector<T>& tree, I vertex, I left, I right, I pos, I value) {
    if (left == right) {
        tree[vertex] = value;
    } else {
        I mid = left + (right - left) / 2;
        if (pos <= mid) {
            update(tree, 2 * vertex, left, mid, pos, value);
        } else {
            update(tree, 2 * vertex + 1, mid + 1, right, pos, value);
        }
        tree[vertex] = tree[2 * vertex] + tree[2 * vertex + 1];
    }
}

int main () {
    ios_base::sync_with_stdio (0); cin.tie (0); cout.tie (0);
    int N, M;
    cin >> N >> M;
    vector<long long> V(N), A(4 * N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> V[i];
    }
    build(A, V, 1, 0, N - 1);
    while (M--) {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1) {
            update(A, 1, 0, N - 1, a, b);
        } else {
            cout << query(A, 1, a, b - 1, 0, N - 1) << "\n";
        }
    }
}

