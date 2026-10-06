class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        if(src == dst) return 0;

        vector<pair<int,int>> adj[n];
        for(auto e : flights){
            adj[e[0]].push_back({e[1],e[2]});
        }

        vector<int> dist(n,1e9);
        dist[src] = 0;
        // {stops, node}
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,src},0});

        while(!q.empty()){
            auto it = q.front();
            int node = it.first.second;
            int steps = it.first.first;
            int dis = it.second;
            q.pop();
            if(steps>k) continue;

            for(auto v : adj[node]){
                int adjNode = v.first;
                int cost = v.second;

                if(cost + dis < dist[adjNode] && steps<=k){
                    dist[adjNode] = cost+dis;
                    
                    q.push({{steps+1,adjNode},dist[adjNode]});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
    }
};
