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

vector<string> g;
vector<vector<int>> vis;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int n;

void ff(int x, int y){
    if (x < 0 || x >= n || y < 0 || y >= n){
        return;
    }
    if (g[x][y] == '.'){
        return;
    }
    if (vis[x][y]){
        return;
    }
    vis[x][y] = 1;
    for (int i = 0; i < 4; i++){
        ff(x+dx[i], y+dy[i]);
    }
}

int main() {
    int t; cin >> t;
    for (int cs = 0; cs < t; cs++){
        cin >> n;
        g.resize(n, "");
        for (int i = 0; i < n; i++){
            cin >> g[i];
        }
        vis.assign(n, vector<int>(n, 0));
        int ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (g[i][j] == 'x' && !vis[i][j]){
                    ans++;
                    ff(i, j);
                }
            }
        }
        cout << "Case " << cs+1 << ": " << ans << '\n';
    }
    return 0;
}
