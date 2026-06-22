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
int m, n, x, y;
char land;

void dfs1(int p, int q){
    if (p >= m || p < 0){
        return;
    }
    if (g[p][q] != land){
        return;
    }
    if (vis[p][q]){
        return;
    }
    vis[p][q] = 2;
    for (int i = 0; i < 4; i++){
        dfs1(p+dx[i], (q+dy[i]+n)%n);
    }
}
int cnt;

void dfs2(int p, int q){
    if (p >= m || p < 0){
        return;
    }
    if (g[p][q] != land){
        return;
    }
    if (vis[p][q]){
        return;
    }
    vis[p][q] = 1;
    cnt++;
    for (int i = 0; i < 4; i++){
        dfs2(p+dx[i], (q+dy[i]+n)%n);
    }
}
int main() {
    while (cin >> m >> n){
        g.resize(m);
        for (int i = 0; i < m; i++){
            cin >> g[i];
        }
        vis.assign(m, vector<int>(n, 0));
        cin >> x >> y;
        land = g[x][y];
        dfs1(x, y);
        int ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (g[i][j] == land && !vis[i][j]){
                    cnt = 0;
                    dfs2(i, j);
                    ans = max(ans, cnt);
                }
            }
        }
        cout << ans << '\n';
        string st; getline(cin, st);
    }
    return 0;
}UV
