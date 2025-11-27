#include <bits/stdc++.h>

using namespace std;

// Use long long for profit to prevent overflow, 
// though with given constraints int would likely suffice.
using ll = long long;

void solve() {
    int k, n;
    // Reading k (max transactions) and n (days)
    if (!(cin >> k >> n)) return;

    vector<int> prices(n);
    for (int i = 0; i < n; ++i) {
        cin >> prices[i];
    }

    // Edge case: No days or no transactions possible
    if (n == 0 || k == 0) {
        cout << 0 << endl;
        return;
    }

    // Optimization: If k is large enough to cover every upward slope (n/2),
    // we switch to a Greedy approach (Infinite transactions allowed).
    // This turns O(N*K) into O(N).
    if (k >= n / 2) {
        ll max_profit = 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[i - 1]) {
                max_profit += (prices[i] - prices[i - 1]);
            }
        }
        cout << max_profit << endl;
        return;
    }

    // Dynamic Programming approach for limited transactions
    // We use a small negative number for uninitialized buy states
    // (INT_MIN can cause overflow when subtracting price)
    vector<ll> buy(k + 1, -1e15); 
    vector<ll> sell(k + 1, 0);

    for (int price : prices) {
        for (int i = 1; i <= k; ++i) {
            // Update the max profit for the i-th buy
            // Either we keep the previous buy state, 
            // or we buy now using the profit from the (i-1)th sell.
            buy[i] = max(buy[i], sell[i - 1] - price);

            // Update the max profit for the i-th sell
            // Either we keep the previous sell state,
            // or we sell now using the stock from the i-th buy.
            sell[i] = max(sell[i], buy[i] + price);
        }
    }

    // The answer is the max profit after at most k transactions (sell[k])
    cout << sell[k] << endl;
}

int main() {
    // Fast I/O for performance
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}