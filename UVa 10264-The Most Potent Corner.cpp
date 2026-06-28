#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define usopen(filename) do{freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);}while(0);
#define f first
#define s second
#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>


int main() {
    int n;
    while (cin >> n){
        vi a(1<<n);
        for (int i = 0; i < (1<<n); i++){
            cin >> a[i];
        }
        vi w(1<<n);
        for (int i = 0; i < (1<<n); i++){
            for (int j = 0; j < n; j++){
                w[i] += a[i^(1<<j)];
            }
        }
        int ans = 0;
        for (int i = 0; i < (1<<n); i++){
            int mx = 0;
            for (int j = 0; j < n; j++){
                mx = max(mx, w[i^(1<<j)]);
            }
            ans = max(ans, mx+w[i]);
        }
        cout << ans << '\n';
    }
    return 0;
}
