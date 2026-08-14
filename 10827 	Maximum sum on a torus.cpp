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


int main() {
    speedup
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<vll> a(2*n+1, vll(2*n+1));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> a[i][j];
                a[i+n][j] = a[i][j+n] = a[i+n][j+n] = a[i][j];
            }
        }
        for (int i = 1; i <= 2*n; i++) {
            for (int j = 1; j <= 2*n; j++) {
                a[i][j] += a[i][j-1];
            }
        }
        ll fans = -1e15;
        for (int i = 1; i <= n; i++) {
            for (int l = 1; l <= n; l++) {
                int j = i+l-1;
                vll pref(2*n+1);
                for (int k = 1; k <= 2*n; k++) {
                    pref[k] = a[k][j]-a[k][i-1];
                    pref[k] += pref[k-1];
                }
                multiset<ll> st;
                st.insert(0);
                ll ans = -1e15;
                for (int k = 1; k <= 2*n; k++) {
                    ans = max(ans, pref[k]-*st.begin());
                    st.insert(pref[k]);
                    if (k >= n) {
                        auto it = st.find(pref[k-n]);
                        if (it != st.end()) st.erase(it);
                    }
                }
                fans = max(fans, ans);
            }
        }
        cout << fans << '\n';
    }
    return 0;
}
