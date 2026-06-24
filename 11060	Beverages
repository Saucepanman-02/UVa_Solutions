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

vector<vi> g;
vector<bool> vis;

int main() {
    speedup
    int n, m;
    int cs = 1;
    while (cin >> n){
        unordered_map<string, int> mp;
        unordered_map<int, string> pm;
        for (int i = 0; i < n; i++){
            string st; cin >> st;
            mp[st] = i, pm[i] = st;
        }
        vis.assign(n, false);
        g.assign(n, vector<int>());
        cin >> m;
        vector<int> indeg(n, 0);
        for (int i = 0; i < m; i++){
            string s1, s2; cin >> s1 >> s2;
            g[mp[s1]].push_back(mp[s2]);
            indeg[mp[s2]]++;
        }
        priority_queue<int, vector<int>, greater<int>> q;

        for (int i = 0; i < n; i++){
            if (!indeg[i]){
                q.push(i);
            }
        }
        vi ans;
        while (!q.empty()){
            int u = q.top(); q.pop();
            if (vis[u]){
                continue;
            }
            ans.push_back(u);
            vis[u] = true;
            for (int &v: g[u]){
                indeg[v]--;
                if (!indeg[v]){
                    q.push(v);
                }
            }
        }
        cout << "Case #" << cs << ": Dilbert should drink beverages in this order:";
        cs++;
        for (int c: ans){
            cout << " " << pm[c];
        }
        cout << "." << '\n';
        cout << '\n';
    }
    return 0;
}
