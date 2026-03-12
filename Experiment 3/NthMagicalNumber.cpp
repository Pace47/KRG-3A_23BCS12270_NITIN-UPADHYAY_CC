class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
        int i = 1, j = 1;
        int nextA = a, nextB = b;
        int ans = 0;

        for(int k = 1; k <= n; k++) {
            if(nextA < nextB) {
                ans = nextA;
                i++;
                nextA = i * a;
            } 
            else if(nextB < nextA) {
                ans = nextB;
                j++;
                nextB = j * b;
            } 
            else {
                ans = nextA;
                i++;
                j++;
                nextA = i * a;
                nextB = j * b;
            }
        }

        return ans % 1000000007;
    }
};
