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
    vi a = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
    int n = 11;
    int m = 3*1e4+1;
    vector<ll> dp(m+1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] <= j) {
                dp[j] += dp[j-a[i-1]];
            }
        }
    }
    db cur;
    while (cin >> cur && cur != 0.00) {
        int r = round(100*cur);
        printf("%6.2f%17lld\n", cur, dp[r]);
    }
    return 0;
}
