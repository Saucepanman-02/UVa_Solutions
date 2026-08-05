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

const int MOD = 1e6;

int main() {
    int l, n;
    while (cin >> l >> n){
        vi a(n+2);
        for (int i = 1; i <= n; i++ ) {
            cin >> a[i];
        }
        a[n+1] = l;
        n++;
        vector<vi> dp(n, vi(n, 1e8));
        for (int i = 1; i <= n; i++) {
            dp[i-1][i-1] = 0;
        }
        for (int le = 2; le <= n; le++) {
            for (int i = 0; i <= n-le; i++) {
                int j = i+le-1;
                int st = a[j+1]-a[i];
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k]+dp[k+1][j]+st);
                }
            }
        }
        cout << "The minimum cutting is " << dp[0][n-1] << "." << endl;
    }
    return 0;
}
