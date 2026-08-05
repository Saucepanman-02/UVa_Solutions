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
    int t; cin >> t;
    while (t--) {
        int m, c; cin >> m >> c;
        vector<vi> a(c+1);
        for (int i = 1; i <= c; i++) {
            int r; cin >> r;
            for (int j = 0; j < r; j++) {
                int u; cin >> u;
                a[i].push_back(u);
            }
        }
        vector<vi> dp(m+1, vi(c+1, -1));
        for (int j = 0; j <= m; j++) {
            dp[j][0] = 0;
        }
        for (int i = 1; i <= c; i++) {
            for (int j = 0; j <= m; j++) {
                for (int u: a[i]) {
                    if (j >= u && dp[j-u][i-1] != -1) {
                        dp[j][i] = max(dp[j][i], dp[j-u][i-1]+u);
                    }
                }
            }
        }
        if (dp[m][c] != -1) {
            cout << dp[m][c] << '\n';
        }else {
            cout << "no solution" << '\n';
        }
    }

    return 0;
}
