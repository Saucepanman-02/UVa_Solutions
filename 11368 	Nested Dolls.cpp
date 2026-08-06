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

vi mlis(vi & a) {
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
            if (c[md] < a[i]) {
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

bool cmp(pii &a, pii& b) {
    if (a.f == b.f) {
        return a.s > b.s;
    }
    return a.f < b.f;
}

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<pii> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].f >> a[i].s;
        }
        sort(a.begin(),a.end(), cmp);
        vi c(n);
        for (int i = 0; i < n; i++) {
            c[i] = a[i].s;
        }
        cout << mlis(c).size() << '\n';
    }
    return 0;
}
