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
    return (ll)((((__int128)p * x % N * x % N) + q) % N);
}

int main() {
    while (cin >> N && !(N == 0)) {
        cin >> p >> q;
        ll a = E(0), b = E(a);
        while (a != b) {
            a = E(a);
            b = E(E(b));
        }
        ll l = 1;
        b = E(a);
        while (a != b) {
            b = E(b);
            l++;
        }
        cout << N-l << '\n';
    }
    return 0;
}
