#include <iostream>
#include <algorithm>

using namespace std;

long long combinations(int n, int k) {
    if (k < 0 || k > n) {
        return 0;
    }
    if (k == 0 || k == n) {
        return 1;
    }
    if (k > n / 2) {
        k = n - k;
    }

    long long result = 1;
    for (int i = 1; i <= k; ++i) {
        result = result * (n - i + 1) / i;
    }
    return result;
}

void solve() {
    int N, T, M;
    if (!(cin >> N >> T >> M)) {
        return;
    }

    long long minimum_required_total = (long long)N * M;

    if (T < minimum_required_total) {
        cout << 0 << endl;
        return;
    }

    int T_new = T - minimum_required_total;

    int n_stars_and_bars = T_new + N - 1;
    int k_bars = N - 1;

    long long result = combinations(n_stars_and_bars, k_bars);

    cout << result << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int K;
    if (!(cin >> K)) {
        return 0;
    }

    while (K--) {
        solve();
    }

    return 0;
}