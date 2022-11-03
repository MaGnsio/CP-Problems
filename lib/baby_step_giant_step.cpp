template <typename T>
T power(T b, T p, T m) {
    T res = 1;
    while (p) {
        if (p & 1) {
            res = ((res % m) * (b % m)) % m;
        }
        b = ((b % m) * (b % m)) % m;
        p >>= 1;
    }
    return res;
}

template <typename T>
T bsgs(T a, T b, T m) {
    a %= m, b %= m;
    T n = sqrt(m) + 1;
    map<T, T> vals;
    for (T p = 1; p <= n; ++p) {
        vals[power(a, p * n, m)] = p;
    }
    for (T q = 0; q <= n; ++q) {
        T cur = (power(a, q, m) * b) % m;
        if (vals.count(cur)) {
            T ans = vals[cur] * n - q;
            return ans;
        }
    }
    return -1;
}
