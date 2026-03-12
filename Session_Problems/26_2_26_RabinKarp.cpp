#include <bits/stdc++.h>
using namespace std;

const int base = 26;

int hashValue(string str) {
    int res = 0;
    for (char c : str) {
        res = res * base + (c - 'a' + 1);
    }
    return res;
}

int main() {
    string s = "abababcab";
    string g = "bca";

    int n = s.length();
    int p = g.length();

    int patHash = hashValue(g);
    int txtHash = hashValue(s.substr(0, p));

    int power = 1;
    for (int i = 1; i <= p - 1; i++) {
        power *= base;
    }

    for (int i = 0; i <= n - p; i++) {
        if (txtHash == patHash) {
            cout << "Matched at index " << i << endl;
        }

        if (i < n - p) {
            txtHash -= (s[i] - 'a' + 1) * power;
            txtHash *= base;
            txtHash += (s[i + p] - 'a' + 1);
        }
    }
    return 0;
}
