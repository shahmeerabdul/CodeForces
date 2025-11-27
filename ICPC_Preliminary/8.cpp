#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> a(n);
        vector<int> b(n);

        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];

        int total = 0;
        int current = 0;
        int start = 0;

        for (int i = 0; i < n; i++) {
            int diff = a[i] - b[i];
            total += diff;
            current += diff;

            if (current < 0) {
                start = i + 1;
                current = 0;
            }
        }

        if (total < 0) {
            cout << -1 << "\n";
        } else {
            cout << start + 1 << "\n";
        }
    }
    return 0;
}