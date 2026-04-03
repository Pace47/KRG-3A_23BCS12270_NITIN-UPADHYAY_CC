#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    // Step 1: Build adjacency list
    vector<pair<int,int>> adj[n];
    
    for(auto &f : flights) {
        adj[f[0]].push_back({f[1], f[2]});
    }

    // Min Heap: {cost, node, stops}
    priority_queue<
        vector<int>,
        vector<vector<int>>,
        greater<vector<int>>
    > pq;

    pq.push({0, src, 0});

    // Distance array to track minimum stops
    vector<int> stopsArr(n, INT_MAX);

    while(!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        int cost = top[0];
        int node = top[1];
        int stops = top[2];

        // If destination reached
        if(node == dst) return cost;

        // If stops exceeded or not optimal
        if(stops > k || stops > stopsArr[node]) continue;

        stopsArr[node] = stops;

        // Explore neighbors
        for(auto &it : adj[node]) {
            int next = it.first;
            int price = it.second;

            pq.push({cost + price, next, stops + 1});
        }
    }

    return -1;
}

int main() {
    int n = 4;

    vector<vector<int>> flights = {
        {0, 1, 100},
        {1, 2, 100},
        {2, 3, 100},
        {0, 3, 500}
    };

    int src = 0;
    int dst = 3;
    int k = 1;

    int result = findCheapestPrice(n, flights, src, dst, k);

    if(result == -1)
        cout << "No valid route found\n";
    else
        cout << "Cheapest Price: " << result << endl;

    return 0;
}
