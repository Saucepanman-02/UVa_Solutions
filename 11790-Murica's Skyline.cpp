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

vi lis(vi & a) {
    int n = a.size();
    vi c;
    if (a.empty()) {
        return a;
    }
    c.push_back(a[0]);
    for (int i = 1; i < n; i++) {
        int l = 0, r = c.size()-1, idx = c.size();
        while (r >= l) {
            int md = (r+l)/2;
            if (c[md] >= a[i]) {
                idx = md;
                r = md-1;
            }else {
                l = md+1;
            }
        }
        if (idx == c.size()) {
            c.push_back(a[i]);
        }else {
            c[idx] = a[i];
        }
    }
    return c;
}

vi mlis(vi & a,vi & w) {
    int n = a.size();
    vi c;
    if (a.empty()) {
        return a;
    }
    c.push_back(a[0]);
    vi ans = {w[0]};
    for (int i = 1; i < n; i++) {
        int l = 0, r = c.size()-1, idx = c.size();
        while (r >= l) {
            int md = (r+l)/2;
            if (c[md] > a[i]) {
                idx = md;
                r = md-1;
            }else {
                l = md+1;
            }
        }
        if (idx == c.size()) {
            c.push_back(a[i]);
            ans.push_back(w[i]);
        }else {
            c[idx] = a[i];
            ans[idx] = w[i];
        }
    }
    return ans;
}


int main() {
    int t; cin >> t;
    for (int r = 0; r < t; r++) {
        int n; cin >> n;
        vi h(n), w(n);
        for (int i = 0; i < n; i++) {
            cin >> h[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> w[i];
        }
        vll dp(n);
        dp[0] = w[0];
        ll ans1 = w[0];
        for (int i = 1; i < n; i++) {
            dp[i] = w[i];
            for (int j = 0; j < i; j++) {
                if (h[i] > h[j]) {
                    dp[i] = max(dp[i], dp[j]+w[i]);
                }
            }
            ans1 = max(ans1, dp[i]);
        }
        vll dp1(n);
        dp1[0] = w[0];
        ll ans2 = w[0];
        for (int i = 1; i < n; i++) {
            dp1[i] = w[i];
            for (int j = 0; j < i; j++) {
                if (h[i] < h[j]) {
                    dp1[i] = max(dp1[i], dp1[j]+w[i]);
                }
            }
            ans2 = max(ans2, dp1[i]);
        }
        if (ans1 >= ans2) {
            cout << "Case " << r+1 << ". Increasing (" << ans1 << "). Decreasing (" << ans2 << ")." << '\n';
        }else {
            cout << "Case " << r+1 << ". Decreasing (" << ans2 << "). Increasing (" << ans1 << ")." << '\n';
        }
    }
    return 0;
}
