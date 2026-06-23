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

vector<vi> g(26);
vector<bool> vis(26);
vector<int> ans;

void dfs(int u){
    if (vis[u]){
        return;
    }
    vis[u] = true;
    for (int v: g[u]){
        dfs(v);
    }
    ans.push_back(u);
}

int main() {
    speedup
    string st;
    vector<string> ls;
    while (cin >> st && (st != "#")){
        ls.push_back(st);
    }
    int sz = ls.size();
    for (int i = 1; i < sz; i++){
        string s1 = ls[i-1], s2 = ls[i];
        int c1 = s1.size(), c2 = s2.size();
        int idx = 0;
        while (idx < min(c1, c2) && (s1[idx] == s2[idx])){
            idx++;
        }
        if (idx == min(c1, c2)){
            continue;
        }
        g[s1[idx]-'A'].push_back(s2[idx]-'A');
    }
    dfs(ls[0][0]-'A');
    reverse(ans.begin(), ans.end());
    for (int c: ans){
        cout << char(c+'A');
    }
    cout << endl;
    return 0;
}
