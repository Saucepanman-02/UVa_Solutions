#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>

vector<string> s;
ll N, p, q;

ll E(ll x) {
    ll ans = 0;
    while (x > 0) {
        ans += (x%10)*(x%10);
        x -= x%10; x/= 10;
    }
    return ans;
}

ll len(ll x) {
    ll a = E(x), b = E(a);
    while (b != a) {
        a = E(a);
        b = E(E(b));
    }
    ll l = 1;
    b = E(a);
    while (b != a) {
        b = E(b); l++;
    }
    if (l != 1) {
        return -1;
    }
    b = x;
    ll cnt = 0;
    while (b != 1) {
        b = E(b);
        cnt++;
    }
    return cnt;
}

int main() {
    int tcs = 0;
    while (cin >> p >> q) {
        if (tcs) {
            cout << '\n'; 
        }
        tcs++;
        for (int i = p; i <= q; i++) {
            ll c = len(i);
            if (c == -1) {
                continue;
            }
            cout << i << ' ' << c+1 << '\n';
        }
    }
    return 0;
}
