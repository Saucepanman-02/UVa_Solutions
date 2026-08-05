#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) do{freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);}while(0);
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>
#define f first
#define s second
#define pdi pair<db, int>

const int MOD = 1e6;

int main() {
    int n, k;
    while (cin >> n >> k && !(n == 0 && k == 0)){
        vector<vector<ll>> dp(n+1, vll(k+1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        for (int j = 1; j < k; j++) {
            for (int i = 0; i <= n; i++) {
                for (int r = 0; r <= i; r++) {
                    dp[i][j] += dp[i-r][j-1];
                    dp[i][j] %= MOD;
                }
            }
        }
        cout << dp[n][k-1] << endl;
    }

    return 0;
}
