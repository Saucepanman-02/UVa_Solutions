#include <bits/stdc++.h>

using namespace std;

#define speedup ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

#define ll long long
#define db double
#define pii pair<int, int>
#define pdd pair<db, db>
#define vi vector<int>
#define vll vector<ll>
#define pll pair<ll, ll>

vector<string> s;
ll N, n;

ll E(ll x) {
    stack<ll> st;
    int sz = s.size(), c = 0;
    ll c1, c2;

    while (c < sz) {
        if (s[c] != "N" && s[c] != "+" && s[c] != "-" &&
            s[c] != "*" && s[c] != "%" && s[c] != "x" &&
            s[c] != "/") {

            st.push(stoll(s[c])%N);

            } else if (s[c] == "+") {
                c1 = st.top(); st.pop();
                c2 = st.top(); st.pop();
                st.push((c2 + c1)%N);

            } else if (s[c] == "-") {
                c1 = st.top(); st.pop();
                c2 = st.top(); st.pop();
                st.push(c2 - c1);

            } else if (s[c] == "*") {
                c1 = st.top(); st.pop();
                c2 = st.top(); st.pop();
                st.push((c2 * c1)%N);

            } else if (s[c] == "/") {
                c1 = st.top(); st.pop();
                c2 = st.top(); st.pop();
                st.push(c2 / c1);

            } else if (s[c] == "N") {
                st.push(N);

            } else if (s[c] == "%") {
                c1 = st.top(); st.pop();
                c2 = st.top(); st.pop();
                st.push(c2 % c1);

            } else if (s[c] == "x") {
                st.push(x%N);
            }

        c++;
    }

    return st.top();
}

int main() {
    while (cin >> N >> n && !(N == 0)) {
        string line;
        getline(cin, line);

        stringstream ss(line);
        string word;

        while (ss >> word) {
            s.push_back(word);
        }

        ll a = E(n), b = E(E(n));
        while (a != b) {
            a = E(a);
            b = E(E(b));
        }
        b = E(a); int l = 1;
        while (a != b) {
            b = E(b); l++;
        }
        cout << l << '\n';
        s.clear();
    }
    return 0;
}
