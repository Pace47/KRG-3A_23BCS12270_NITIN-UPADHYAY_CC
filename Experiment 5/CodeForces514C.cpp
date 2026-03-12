#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD1 = 1e9 + 7;
const ll MOD2 = 1e9 + 9;
const ll BASE1 = 31;
const ll BASE2 = 37;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    unordered_set<ll> st;

    auto combine = [](ll h1, ll h2) {
        return (h1 << 32) ^ h2;
    };

    while (n--) {
        string s;
        cin >> s;

        ll h1 = 0, h2 = 0;
        ll p1 = 1, p2 = 1;

        for (char c : s) {
            int val = c - 'a' + 1;
            h1 = (h1 + val * p1) % MOD1;
            h2 = (h2 + val * p2) % MOD2;
            p1 = (p1 * BASE1) % MOD1;
            p2 = (p2 * BASE2) % MOD2;
        }

        st.insert(combine(h1, h2));
    }

    while (m--) {
        string s;
        cin >> s;

        int len = s.size();

        vector<ll> pow1(len), pow2(len);
        ll h1 = 0, h2 = 0;
        ll p1 = 1, p2 = 1;

        for (int i = 0; i < len; i++) {
            pow1[i] = p1;
            pow2[i] = p2;

            int val = s[i] - 'a' + 1;
            h1 = (h1 + val * p1) % MOD1;
            h2 = (h2 + val * p2) % MOD2;

            p1 = (p1 * BASE1) % MOD1;
            p2 = (p2 * BASE2) % MOD2;
        }

        bool found = false;

        for (int i = 0; i < len && !found; i++) {
            int original = s[i] - 'a' + 1;

            for (char c = 'a'; c <= 'c'; c++) {
                if (c == s[i]) continue;

                int val = c - 'a' + 1;

                ll nh1 = h1;
                ll nh2 = h2;

                nh1 = (nh1 - original * pow1[i] % MOD1 + MOD1) % MOD1;
                nh2 = (nh2 - original * pow2[i] % MOD2 + MOD2) % MOD2;

                nh1 = (nh1 + val * pow1[i]) % MOD1;
                nh2 = (nh2 + val * pow2[i]) % MOD2;

                if (st.count(combine(nh1, nh2))) {
                    found = true;
                    break;
                }
            }
        }

        cout << (found ? "YES\n" : "NO\n");
    }

    return 0;
}
