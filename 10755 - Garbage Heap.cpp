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
    int t; cin >> t;
    while (t--) {
        int a, b, c; cin >> a >> b >> c;
        vector<vector<vi>> g(a, vector<vi>(b+1, vi(c+1)));
        for (int i = 0; i < a; i++) {
            for (int j = 1; j <= b; j++) {
                for (int k = 1; k <= c; k++) {
                    cin >> g[i][j][k];
                    g[i][j][k] += g[i][j-1][k]+g[i][j][k-1]-g[i][j-1][k-1];
                }
            }
        }
        int fans = 0;
        for (int l1 = 1; l1 <= b; l1++) { for (int l2 = l1; l2 <= b; l2++) {
            for (int r1 = 1; r1 <= c; r1++) { for (int r2 = r1; r2 <= c; r2++) {
                int sum = 0, ans = 0;
                for (int i = 0; i < a; i++) {
                    sum += g[i][l2][r2] - g[i][l1-1][r2]-g[i][l2][r1-1] + g[i][l1-1][r1-1];
                    ans = max(ans, sum);
                    if (sum < 0) sum = 0;
                }
                fans = max(fans, ans);
            }
            }
        }
        }
        cout << fans << '\n';
    }
    return 0;
}
