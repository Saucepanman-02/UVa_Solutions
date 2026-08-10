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


int main() {
    int m, n;
    while (cin >> m >> n) {
        vector<vi> dp(m+201, vi(n+1, -1));
        vi w(n), v(n);
        for (int i = 0; i < n; i++) {
            cin >> w[i] >> v[i];
        }
        for (int i = 0; i <= n; i++) {
            dp[0][i] = 0;
        }
        for (int i = 1; i <= m+200; i++) {
            for (int j = 1; j <= n; j++) {
                if (w[j-1] > i) {
                    dp[i][j] = dp[i][j-1];
                    continue;
                }
                if (dp[i-w[j-1]][j-1] != -1)
                    dp[i][j] = max(dp[i][j-1], dp[i-w[j-1]][j-1]+v[j-1]);
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        int ans = 0;
        for (int i = 0; i <= m; i++) {
            ans = max(ans, dp[i][n]);
        }
        for (int i = 2001; i <= m+200; i++) {
            ans = max(ans, dp[i][n]);
        }
        cout << ans << '\n';
    }
    return 0;
}
