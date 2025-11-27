#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (cin >> n) {
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.rbegin(), a.rend());

        int m;
        cin >> m;

        int scoreofA = 0;
        int scoreofB = 0;

        for (int i = 0; i < m; i++) {
            string who, action;
            cin >> who >> action;

            int val = a[i];

            if (action == "pick") {
                if (who == "A") scoreofA += val;
                else scoreofB += val;
            }
        }

        if (scoreofA > scoreofB) {
            cout << "A " << scoreofA - scoreofB << "\n";
        } else {
            cout << "B " << scoreofB - scoreofA << "\n";
        }
    }
    return 0;
}