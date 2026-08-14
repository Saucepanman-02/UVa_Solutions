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
        int m, S; cin >> m >> S;
        vector<vi> dp(S+1, vi(S+1, 1e9));
        dp[0][0] = 0;
        vector<pii> a(m);
        for (int i = 0; i < m; i++) {
            cin >> a[i].f >> a[i].s;
        }
        for (pii p: a) {
            for (int x = p.f; x <= S; x++) {
                for (int y = p.s; y <= S; y++) {
                    dp[x][y] = min(dp[x][y], dp[x-p.f][y-p.s]+1);
                }
            }
        }
        int ans = 1e9;
        for (int i = 0; i <= S; i++) {
            for (int j = 0; j <= S; j++) {
                if (i*i+j*j==S*S) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }
        if (ans == 1e9) {
            cout << "not possible" << '\n';
        }else {
            cout << ans << '\n';
        }
    }
    return 0;
}
