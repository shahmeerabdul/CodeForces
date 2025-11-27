#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        long long n, m, x;
        cin >> n >> m >> x;

        long long col = (x - 1) / n + 1;     // which column x is in
        long long row = (x - 1) % n + 1;     // which row x is in

        long long ans = (row - 1) * m + col; // row-major index

        cout << ans << "\n";
    }
}
