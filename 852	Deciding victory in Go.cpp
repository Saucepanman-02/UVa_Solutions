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

vector<string> g(9);
vector<vector<int>> vis;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int cnt1, cnt2; char c;
int mc;

void dfs(int x, int y){
    if (x < 0 || x >= 9 || y < 0 || y >= 9){
        return;
    }
    if (g[x][y] == 'O'){
        cnt1++;
        return;
    }
    if (g[x][y] == 'X'){
        cnt2++;
        return;
    }
    if (vis[x][y]){
        return;
    }
    vis[x][y] = 1;
    if (g[x][y] == '.') {
        mc++;
        for (int i = 0; i < 4; i++) {
            dfs(x + dx[i], y + dy[i]);
        }
    }
}

int main() {
    int t; cin >> t;
    while (t--){
        for (int i = 0; i < 9; i++){
            cin >> g[i];
        }
        vis.assign(9, vector<int>(9, 0));
        int bp = 0, wp = 0;
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                if (g[i][j] == '.' && !vis[i][j]){
                    cnt1 = 0, mc = 0, cnt2 = 0;
                    dfs(i, j);
                    if (cnt1 == 0){
                        bp += mc; //cout << "B" << mc << endl;
                    }
                    if (cnt2 == 0){
                        wp += mc; //cout << "W" << mc << endl;
                    }
                }
                if (g[i][j] == 'O'){
                    wp++;
                }else if (g[i][j] == 'X'){
                    bp++;
                }
            }
        }
        cout << "Black " << bp << " White " << wp << '\n';
    }
    return 0;
}
