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
#define ceil(n, r) (ll)((n+r-1)/r)
#define floor(n, r) (ll)(n/r);


int main() {
    speedup
    int tcs; cin >> tcs;
    while (tcs--) {
        int n; cin >> n;
        n /= 100;
        vector<vi> dist(10, vi(n, 0));
        for (int i = 9; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                cin >> dist[i][j];
                dist[i][j] *= -1;
            }
        }
        vector<vi> dp(n+1, vi(10, 1e9));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 10; j++) {
                dp[i][j] = min(dp[i][j], dp[i-1][j]+30+dist[j][i-1]);
                if (j != 9) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j+1]+20+dist[j+1][i-1]);
                }
                if (j != 0) {
                    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+60+dist[j-1][i-1]);
                }
            }
        }
        cout << dp[n][0] << '\n';
        cout << '\n';
    }
    return 0;
}
