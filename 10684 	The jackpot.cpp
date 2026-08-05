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

int main() {
    int n;
    while (cin >> n && n) {
        vi a(n);
        int sum = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            sum += a[i];
            ans = max(ans, sum);
            if (sum < 0) sum = 0;
        }
        if (ans) {
            cout << "The maximum winning streak is " << ans << "." << endl;
        }else {
            cout << "Losing streak." << endl;
        }
    }
    return 0;
}
