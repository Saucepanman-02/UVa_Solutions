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
    for (int i = 1; i <= tcs; i++){
        int n; cin >> n;
        int bs = 0;
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            if (c == '1') {
                bs |= (1<<(i));
            }
        }
        vector<int> vpn(n);
        for (int i = 0; i < n; i++) {
            int cur = 0;
            for (int j = 0; j < n; j++) {
                char c; cin >> c;
                if (c == '1') {
                    cur |= (1<<(j));
                }
            }
            vpn[i] = cur;
        }
        vector<vector<ll>> dp((1<<n), vll(n, 0));
        for (int i = 0; i < n; i++) {
            if ((1<<i)&bs) {
                dp[(1<<i)][i] = 1;
            }
        }
        for (int mask = 1; mask < (1<<n); mask++) {
            for (int u = 0; u < n; u++) {
                if (mask&(1<<u)) {
                    if (bs&(1<<u)) {
                        for (int v = 0; v < n; v++) {
                            if (mask&(1<<v) && u != v) {
                                dp[mask][u] += dp[mask^(1<<u)][v];
                            }
                        }
                    }else {
                        int flag = 0;
                        for (int v = 0; v < n; v++) {
                            if (mask&(1<<v) && u != v && vpn[v]&(1<<u)) {
                                flag = 1;
                            }
                        }
                        if (flag) {
                            for (int v = 0; v < n; v++) {
                                if (mask&(1<<v) && u != v) {
                                    dp[mask][u] += dp[mask^(1<<u)][v];
                                }
                            }
                        }
                    }
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[(1<<n)-1][i];
        }
        cout << "Case " << i << ": " << ans << '\n';
    }

    return 0;
}
