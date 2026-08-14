#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(file) \
    do { \
        freopen(file ".in", "r", stdin); \
        freopen(file ".out", "w", stdout); \
    } while (0)

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
    return sqrt((a.f - b.f) * (a.f - b.f) +
                (a.s - b.s) * (a.s - b.s)) + 16;
}

/*
db calc(vector<pii> a) {
    int n = a.size();

    vector<vector<db>> dp((1 << n), vector<db>(n, 1e9));

    dp[1][0] = 0;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 1; u < n; u++) {
            if (mask & (1 << u)) {
                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) && u != v) {
                        if (dp[mask][u] >
                            dp[mask ^ (1 << u)][v] + cost(a[u], a[v])) {

                            dp[mask][u] =
                                dp[mask ^ (1 << u)][v] + cost(a[u], a[v]);
                        }
                    }
                }
            }
        }
    }

    db ans = 1e9;

    for (int i = 1; i < n; i++) {
        ans = min(ans, dp[(1 << n) - 1][i]);
    }

    return ans;
}
*/

void back_track(vector<pii> a) {
    int n = a.size();

    vector<vector<int>> p((1 << n), vector<int>(n, -1));
    vector<vector<db>> dp((1 << n), vector<db>(n, 1e9));

    dp[1][0] = 0;
    p[1][0] = -1;

    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 1; u < n; u++) {
            if (mask & (1 << u)) {
                for (int v = 0; v < n; v++) {
                    if ((mask & (1 << v)) && u != v) {
                        if (dp[mask][u] >
                            dp[mask ^ (1 << u)][v] + cost(a[u], a[v])) {

                            dp[mask][u] =
                                dp[mask ^ (1 << u)][v] + cost(a[u], a[v]);

                            p[mask][u] = v;
                        }
                    }
                }
            }
        }
    }

    db ans = 1e9;
    int cr = -1;

    for (int i = 1; i < n; i++) {
        if (ans > dp[(1 << n) - 1][i]) {
            ans = dp[(1 << n) - 1][i];
            cr = i;
        }
    }

    int nmask = -1, nc = -1, nfmask = -1, nfc = -1;

    for (int mask = 1; mask < (1 << n); mask++) {
        if (!(mask & 1)) {
            continue;
        }

        int fmask = (1 << n) - 1 - mask;
        fmask++;

        for (int u = 1; u < n; u++) {
            if ((1 << u) & mask) {
                for (int v = 1; v < n; v++) {
                    if (fmask & (1 << v)) {
                        if (ans > dp[mask][u] + dp[fmask][v]) {

                            ans = dp[mask][u] + dp[fmask][v];

                            nmask = mask;
                            nfmask = fmask;

                            nc = u;
                            nfc = v;
                        }
                    }
                }
            }
        }
    }

    vi ls;
    vi ls1;

    if (nmask == -1) {
        int c = cr;
        int mask = (1 << n) - 1;

        while (c != -1) {
            ls.push_back(c);

            int pmask = mask ^ (1 << c);
            int pc = p[mask][c];

            mask = pmask;
            c = pc;
        }

    } else {
        int mask = nmask;
        int c = nc;

        while (c != -1) {
            ls.push_back(c);

            int pmask = mask ^ (1 << c);
            int pc = p[mask][c];

            mask = pmask;
            c = pc;
        }

        mask = nfmask;
        c = nfc;

        while (c != -1) {
            ls1.push_back(c);

            int pmask = mask ^ (1 << c);
            int pc = p[mask][c];

            mask = pmask;
            c = pc;
        }

        if (ls1.size()) {
            ls1.pop_back();
        }

        reverse(ls1.begin(), ls1.end());

        for (int r : ls1) {
            ls.push_back(r);
        }
    }

    db fans = 0;

    for (int i = 0; i < n - 1; i++) {
        printf(
            "Cable requirement to connect (%d,%d) to (%d,%d) "
            "is %.2f feet.\n",

            a[ls[i]].f,
            a[ls[i]].s,

            a[ls[i + 1]].f,
            a[ls[i + 1]].s,

            cost(a[ls[i]], a[ls[i + 1]])
        );

        fans += cost(a[ls[i]], a[ls[i + 1]]);
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

        printf(
            "**********************************************************\n"
        );

        printf("Network #%d\n", tcs++);

        back_track(a);
    }

    return 0;
}
