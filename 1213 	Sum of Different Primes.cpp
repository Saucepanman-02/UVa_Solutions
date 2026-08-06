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

bool isprime(int c) {
    for (int i = 2; i < c; i++) {
        if (c%i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    while (cin >> n >> k && !(n == 0 && k == 0)) {
        vi p;
        for (int i = 2; i <= n; i++) {
            if (isprime(i)) {
                p.push_back(i);
            }
        }
        int pr = p.size();
        vector<vi> dp(n+1, vi(k+1));
        dp[0][0] = 1;
        for (int ps = 0; ps < pr; ps++) {
            for (int st = n; st >= 2; st--) {
                for (int r = k; r >= 1; r--) {
                    if (p[ps] > st) {
                        continue;
                    }
                    dp[st][r] += dp[st-p[ps]][r-1];
                }
            }
        }
        cout << dp[n][k] << endl;
    }
    return 0;
}
