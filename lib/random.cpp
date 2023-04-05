mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

function<int64_t(int64_t, int64_t)> random = [&](int64_t x, int64_t y) {
    return uniform_int_distribution<int64_t>(x, y)(rng);
};
