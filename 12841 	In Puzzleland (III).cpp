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
    speedup
    int tcs; cin >> tcs;
    for (int t = 1; t <= tcs; t++) {
        int n, m; cin >> n >> m;
        vector<char> a(n);
        map<char, int> mp;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            mp[a[i]] = i;
        }
        vector<vi> dist(n, vi(n, 0));
        for (int i = 0; i < m; i++) {
            char u, v; cin >> u >> v;
            dist[mp[u]][mp[v]] = dist[mp[v]][mp[u]] = 1;
        }
        vector<vector<string>> dp((1<<n), vector<string>(n, "123"));
        dp[1][0] = a[0];
        for (int mask = 1; mask < (1<<n); mask++) {
            for (int u = 0; u < n; u++) {
                if (mask&(1<<u)) {
                    for (int v = 0; v < n; v++) {
                        if (mask&(1<<v) && u != v && dist[u][v] && dp[mask^(1<<u)][v] != "123") {
                            string dm = dp[mask^(1<<u)][v];
                            dm.push_back(a[u]);
                            if (dp[mask][u] == "123") {
                                dp[mask][u] = dm;
                            }else if (dp[mask][u] > dm) {
                                dp[mask][u] = dm;
                            }
                        }
                    }
                }
            }
        }
        string ans = dp[(1<<n)-1][n-1];
        if (ans == "123") {
            cout << "Case " << t << ": impossible\n";
        }else {
            cout << "Case " << t << ": " << ans << '\n';
        }
    }

    return 0;
}
