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
    vi a = {5, 10, 20, 50, 100, 200};
    vi ft = {0, 0, 0, 0, 0, 0};
    vector<int> dp(1e4+1, 1e9);
    dp[0] = 0;
    for (int c: a) {
        for (int i = c; i <= 1e4; i++) {
            dp[i] = min(dp[i], dp[i-c]+1);
        }
    }
    for (int i = 0; i < 6; i++) {
        cin >> ft[i];
    }
    while (ft[0]+ft[1]+ft[2]+ft[3]+ft[4]+ft[5]){
        db cur; cin >> cur;
        int m = round(100*cur);
        vector<int> dp1(1e4+1, 1e9);
        dp1[0] = 0;
        for (int c = 0; c < 6; c++) {
            for (int i = 1e4; i >= 0; i--) {
                for (int j = 0; j <= ft[c]; j++) {
                    if (i-j*a[c] < 0) {
                        continue;
                    }
                    dp1[i] = min(dp1[i-j*a[c]]+j, dp1[i]);
                }
            }
        }
        int ans = 1e9;
        for (int i = m; i <= 1e4; i++) {
            ans = min(ans, dp1[i]+dp[i-m]);
        }
        printf("%3d\n", ans);
        for (int i = 0; i < 6; i++) {
            cin >> ft[i];
        }
    }
    return 0;
}
