#include <bits/stdc++.h>
using namespace std;

vector<string> g;
int n, m;
int cnt;

int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};

void dfs(int x, int y, vector<vector<int>>& vis) {
    if (x < 0 || x >= n || y < 0 || y >= m) return;
    if (vis[x][y]) return;
    if (g[x][y] != 'W') return;

    vis[x][y] = 1;
    cnt++;

    for (int k = 0; k < 8; k++)
        dfs(x + dx[k], y + dy[k], vis);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    string line;
    getline(cin, line); // consume endline after T
    getline(cin, line); // consume blank line

    while (T--) {
        g.clear();

        // Read grid
        while (getline(cin, line) && !line.empty() &&
               (line[0] == 'W' || line[0] == 'L')) {
            g.push_back(line);
        }

        n = g.size();
        m = g[0].size();

        // Process queries
        do {
            if (line.empty()) break;

            stringstream ss(line);
            int r, c;
            ss >> r >> c;

            vector<vector<int>> vis(n, vector<int>(m, 0));
            cnt = 0;
            dfs(r - 1, c - 1, vis);

            cout << cnt << '\n';

        } while (getline(cin, line) && !line.empty());

        if (T) cout << '\n';
    }

    return 0;
}
