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


db cost(pdd a, pdd b) {
    return sqrt((a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s))+16;
}

/*
db calc(vector<pii> a) {
    int n = a.size();
    vector<vector<db>> dp((1<<n), vector<db>(n, 1e9));
    dp[1][0] = 0;
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int u = 1; u < n; u++) {
            if (mask&(1<<u)) {
                for (int v = 0; v < n; v++) {
                    if (mask&(1<<v) && u != v) {
                        if (dp[mask][u] > dp[mask^(1<<u)][v]+cost(a[u], a[v])) {
                            dp[mask][u] = dp[mask^(1<<u)][v]+cost(a[u], a[v]);
                        }
                    }
                }
            }
        }
    }
    db ans = 1e9;
    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[(1<<n)-1][i]);
    }
    return ans;
}*/

void back_track(vector<pii> a) {
    int n = a.size();
    vector<vector<int>> p((1<<n), vector<int>(n, -1));
    vector<vector<db>> dp((1<<n), vector<db>(n, 1e9));
    for (int i = 0; i < n; i++) {
        dp[(1<<i)][i] = 0;
    }
    for (int mask = 1; mask < (1<<n); mask++) {
        for (int u = 0; u < n; u++) {
            if (mask&(1<<u)) {
                for (int v = 0; v < n; v++) {
                    if (mask&(1<<v) && u != v) {
                        if (dp[mask][u] > dp[mask^(1<<u)][v]+cost(a[u], a[v])) {
                            dp[mask][u] = dp[mask^(1<<u)][v]+cost(a[u], a[v]);
                            p[mask][u] = v;
                        }
                    }
                }
            }
        }
    }
    db ans = 1e15; int cr = -1;
    for (int i = 0; i < n; i++) {
        if (ans > dp[(1<<n)-1][i]) {
            ans = dp[(1<<n)-1][i];
            cr = i;
        }
    }
    vi ls;
    int c = cr;
    int mask = (1<<n)-1;
    while (c != -1) {
        ls.push_back(c);
        int pmask = mask^(1<<c);
        int pc = p[mask][c];
        mask = pmask;
        c = pc;
    }
    db fans = 0;
    for (int i = 0; i < n-1; i++) {
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n", a[ls[i]].f , a[ls[i]].s, a[ls[i+1]].f, a[ls[i+1]].s, cost(a[ls[i]], a[ls[i+1]]));
        fans += cost(a[ls[i]], a[ls[i+1]]);
    }
    printf("Number of feet of cable required is %.2lf.\n", fans);
}
int main() {
    speedup
    int n;
    int tcs = 1;
    while (cin >> n && n) {
        vector<pii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].f >> a[i].s;
        }
        printf("**********************************************************\n");
        printf("Network #%d\n", tcs++);
        back_track(a);
    }
    return 0;
}
