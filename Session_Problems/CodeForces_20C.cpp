#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,m;
    cin>>n>>m;

    vector<pair<int,int>> graph[n+1];

    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;

        graph[a].push_back({b,w});
        graph[b].push_back({a,w});
    }

    vector<long long> dist(n+1,LLONG_MAX);
    vector<int> parent(n+1);

    for(int i=1;i<=n;i++) parent[i]=i;

    priority_queue<pair<long long,int>,
    vector<pair<long long,int>>,
    greater<pair<long long,int>>> pq;

    dist[1]=0;
    pq.push({0,1});

    while(!pq.empty()){

        auto it=pq.top();
        pq.pop();

        long long cost=it.first;
        int node=it.second;

        for(auto adj:graph[node]){

            int v=adj.first;
            int wt=adj.second;

            if(cost+wt < dist[v]){
                dist[v]=cost+wt;
                parent[v]=node;
                pq.push({dist[v],v});
            }
        }
    }

    if(dist[n]==LLONG_MAX){
        cout<<-1;
        return 0;
    }

    vector<int> path;

    int node=n;

    while(parent[node]!=node){
        path.push_back(node);
        node=parent[node];
    }

    path.push_back(1);

    reverse(path.begin(),path.end());

    for(auto x:path) cout<<x<<" ";

}
