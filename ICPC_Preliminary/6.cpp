#include <bits/stdc++.h>
using namespace std;

#define int long long
const int MOD = 1000000007;
const int OFFSET = 2005;
const int MAX_DIM = 4010;

int dp[MAX_DIM][MAX_DIM];
int fact[8005], invFact[8005];
int a[200005], b[200005];

int power(int base, int exp) {
    int result = 1;
    base =base% MOD;
    while (exp > 0) {
        if (exp % 2 == 1) result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp =exp/ 2;
    }
    return result;
}

int modinv(int n) {
    return power(n, MOD - 2);
}

void precompute() {
    fact[0] = 1;
    invFact[0] = 1;
    for (int i = 1; i <= 8000; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
        invFact[i] = modinv(fact[i]);
    }
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * invFact[r] % MOD * invFact[n - r] % MOD;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    precompute();

    int n;
    if (cin >> n) {
        for (int i = 0; i < n; i++) {
            cin >> a[i] >> b[i];
            dp[-a[i] + OFFSET][-b[i] + OFFSET]++;
        }

        for (int i = 1; i < MAX_DIM; i++) {
            for (int j = 1; j < MAX_DIM; j++) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j] + dp[i][j - 1]) % MOD;
            }
        }

        int total = 0;
        int self = 0;

        for (int i = 0; i < n; i++) {
            total = (total + dp[a[i] + OFFSET][b[i] + OFFSET]) % MOD;

            int combinedA = a[i] * 2;
            int combinedB = b[i] * 2;
            self = (self + nCr(combinedA + combinedB, combinedA)) % MOD;
        }

        int ans = (total - self + MOD) % MOD;
        ans = (ans * modinv(2)) % MOD;

        cout << ans << "\n";
    }
    return 0;
}