#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> idx;
int a[200005];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    if (cin >> n >> q) {
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            idx[a[i]].push_back(i);
        }

        while (q--) {
            int l, r;
            cin >> l >> r;

            int len = r - l + 1;
            int ans = 0;

            for (int k = 0; k < 25; k++) {
                int p = uniform_int_distribution<int>(l, r)(rng);
                int val = a[p];
                
                int cnt = upper_bound(idx[val].begin(), idx[val].end(), r) - 
                          lower_bound(idx[val].begin(), idx[val].end(), l);

                if (cnt > len / 2) {
                    ans = val;
                    break;
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}