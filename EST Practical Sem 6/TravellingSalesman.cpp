#include <bits/stdc++.h>
using namespace std;

int dp[1 << 20][20];
vector<vector<int>> dist;
int n;

int tsp(int mask, int pos)
{
    if (mask == (1 << n) - 1)
    {
        return dist[pos][0];
    }

    if (dp[mask][pos] != -1)
    {
        return dp[mask][pos];
    }

    int ans = INT_MAX;

    for (int city = 0; city < n; city++)
    {
        if ((mask & (1 << city)) == 0)
        {
            int newMask = mask | (1 << city);
            int cost = dist[pos][city] + tsp(newMask, city);
            ans = min(ans, cost);
        }
    }

    return dp[mask][pos] = ans;
}

int main()
{
    cin >> n;
    dist.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> dist[i][j];
        }
    }

    memset(dp, -1, sizeof(dp));

    int minCost = tsp(1, 0);

    cout << "Minimum cost: " << minCost << endl;

    return 0;
}