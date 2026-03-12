#include <bits/stdc++.h>
using namespace std;

long long sumOfDifferentBits(vector<int>& A) {
    int n = A.size();
    long long total = 0;

    for (int bit = 0; bit < 32; bit++) {
        long long count1 = 0;

        for (int i = 0; i < n; i++) {
            if (A[i] & (1LL << bit))   
                count1++;
        }

        long long count0 = n - count1;
        total += count1 * count0;
    }

    return 2 * total;
}


int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++){
        cin>>A[i];
    }
    cout << sumOfDifferentBits(A);
    return 0;
}
