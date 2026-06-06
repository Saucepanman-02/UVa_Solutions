#include <bits/stdc++.h>

using namespace std;

#define usopen(filename) do{freopen(filename".in", "r", stdin); freopen(filename".out", "w", stdout);}while(0);


int main(){
    int n, m; 
    cin >> n >> m;
    while (!(n == 0 && m == 0)){
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++){
            cin >> a[i];
        }
        for (int i = 0; i < m; i++){
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        int ca = 0, cb = 0;
        if (n > m){
            cout << "Loowater is doomed!" << '\n';
        }else{
            int ans = 0;
            while (ca < n && cb < m){
                if (a[ca] <= b[cb]){
                    ans += b[cb];
                    ca++, cb++;
                }else{
                    cb++;
                }
            }
            if (ca < n){
                cout << "Loowater is doomed!" << '\n';
            }else{
                cout << ans << '\n';
            }
        }
        cin >> n >> m;
    }
    
    return 0;
}
