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
#define pid pair<int, db>

int main() {
    speedup
    int tcs; cin >> tcs;
    while (tcs--) {
        int n, m; cin >> n >> m;
        vector<vector<db>> dist(n+1, vector<db>(n+1, 1e10));
        for (int i = 0; i < m; i++) {
            int u, v; db d; cin >> u >> v >> d;
            dist[u][v] = min(dist[u][v], d);
            dist[v][u] = min(dist[v][u], d);
        }
        for (int i = 0; i <= n; i++) dist[i][i] = 0;
        for (int k = 0; k <= n; k++)
            for (int i = 0; i <= n; i++)
                for (int j = 0; j <= n; j++)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        int p; cin  >> p;
        vector<pid> pr(p);
        for (int i = 0; i < p; i++) {
            cin >> pr[i].f >> pr[i].s;
        }

        vector<vector<db>> dp((1<<p), vector<db>(p, -1e9));
        for (int i = 0; i < p; i++) {
            dp[(1<<i)][i] = pr[i].s-dist[0][pr[i].f];
        }
        for (int mask = 1; mask < (1<<p); mask++) {
            for (int u = 0; u < p; u++) {
                if (mask&(1<<u)) {
                    for (int v = 0; v < p; v++) {
                        if (mask&(1<<v) && u != v){
                            dp[mask][u] = max(dp[mask][u], dp[mask^(1<<u)][v]+pr[u].s-dist[pr[u].f][pr[v].f]);
                        }
                    }
                }
            }
        }
        db ans = 0;
        for (int mask = 1; mask < (1 << p); mask++) {
            for (int i = 0; i < p; i++) {
                if (mask & (1 << i)) {
                    ans = max(ans,
                              dp[mask][i]
                              - dist[pr[i].f][0]);
                }
            }
        }
        if (ans > 1e-9) {
            printf("Daniel can save $%.2f\n", ans);
        }else {
            printf("Don't leave the house\n");
        }
    }
    return 0;
}
