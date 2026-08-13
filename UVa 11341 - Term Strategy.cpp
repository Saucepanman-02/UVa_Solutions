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
#define LSOne(x) (x&(x-1))^x



int main() {
    speedup
    int t; cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vi> a(n+1, vi(m+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        vector<vi> dp(n+1, vi(m+1, -1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                for (int k = 1; k <= j; k++) {
                    if (dp[i-1][j-k] != -1 && a[i][k] >= 5) {
                        dp[i][j] = max(dp[i][j], dp[i-1][j-k]+a[i][k]);
                    }
                }
            }
        }
        db ans = -1;
        for (int i = 0; i <= m; i++) {
            ans = max(ans, (db)dp[n][i]);
        }
        if (ans != -1) {
            printf("Maximal possible average mark - %.2f.\n", (ans/n));
        }else {
            printf("Peter, you shouldn't have played billiard that much.\n");
        }
    }
    return 0;
}
