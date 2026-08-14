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
    string line;
    vector<vll> dp(311, vll(1010, 0));
    dp[0][0] = 1;
    for (int c = 1; c <= 310; c++) {
        for (int i = c; i <= 310; i++) {
            for (int j = 1; j <= 1009; j++) {
                dp[i][j] += dp[i-c][j-1];
            }
        }
    }
    while (getline(cin, line)) {
        stringstream ss(line);
        char st[6];
        vi a;
        while (ss >> st) {
            a.push_back(atoi(st));
        }
        if (a.size() == 1) {
            int n = a[0];
            ll ans = 0;
            for (int i = 0; i <= n; i++) {
                ans += dp[n][i];
            }
            cout << ans << '\n';
        }else if (a.size()==2) {
            int n = a[0];
            int l1 = min(a[1], 300);
            ll ans = 0;
            for (int i = 0; i <= l1; i++) {
                ans += dp[n][i];
            }
            cout << ans << '\n';
        }else {
            int n = a[0];
            int l1 = min(a[1], 300);
            int l2 = min(a[2], 300);
            ll ans = 0;
            for (int i = l1; i <= l2; i++) {
                ans += dp[n][i];
            }
            cout << ans << '\n';
        }
    }
    return 0;
}
