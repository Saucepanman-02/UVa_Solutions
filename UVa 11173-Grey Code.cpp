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

void solve(int k, int n){
    int cur = k;
    int ans = 0;
    for (int i = n-1; i >= 0; i--){
        if (cur >= (1<<(i))){
            ans |= (1<< i);
            cur -= (1 << i);
            cur = ((1<<i)-1 - cur);
        }
    }
    cout << ans << endl;
}
int main() {
    speedup
    int n; cin >> n;
    while (n--){
        int r, st;
        cin >> r >> st;
        cout << (st ^ (st >> 1)) << endl;
    }
    return 0;
}
