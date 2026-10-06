class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[n+1];
        for(auto e : times){
            adj[e[0]].push_back({e[1],e[2]});
        }
        // {dist,node}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,1e9);
        dist[0]=0;
        dist[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            auto it = pq.top();
            int node = it.second;
            int dis = it.first;
            pq.pop();

            // if(node == n && dis!=1e9) return dis;
            for(auto v : adj[node]){
                int adjNode = v.first;
                int wt = v.second;

                if(wt+dis < dist[adjNode]){
                    dist[adjNode] = wt+dis;
                    
                    pq.push({dist[adjNode],adjNode});
                }

            }
        }
        int maxtime=0;
        for(auto d : dist){
            if(d==1e9) return -1;
            maxtime = max(d,maxtime);
        }
        return maxtime;
    }
};
