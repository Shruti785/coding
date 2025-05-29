class Solution {
    using pi = pair<int,int> ;
    using ll = long long ;
    vector<int> dp ;
    vector<bool> vis ;
    ll MOD = 1e9 + 7 ;
    vector<int> dijkstras(vector<vector<pi>> &adj){
        const int n = adj.size() ;
        vector<int> dist(n,INT_MAX) ;
        dist[n - 1] = 0 ;
        priority_queue<pi,vector<pi>,greater<pi>> pq ;
        pq.push({0,n-1}) ;
        while(!pq.empty()){
            auto [d,u] = pq.top() ;
            pq.pop() ;
            if(d > dist[u]) continue ;
            for(auto [v,w] : adj[u]){
                if(dist[v] > dist[u] + w){
                    dist[v] = dist[u] + w ;
                    pq.push({dist[v],v}) ;
                }
            }
        }
        return dist ;
    }
    ll dfs(vector<vector<pi>> &adj, vector<int> &dist, int u){
        if(dp[u] != -1) return dp[u] ;
        if(u == adj.size() - 1){
           return 1 ;
        }
        vis[u] = true ;
        ll curr = 0 ;
        for(auto [v,w] : adj[u]){
            if(!vis[v] && dist[v] < dist[u]) curr = (curr + dfs(adj,dist,v)) % MOD ;
        }
        vis[u] = false ;
        return dp[u] = curr ;
    }
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        dp.resize(n,-1) ;
        vis.resize(n,false) ;
        vector<vector<pi>> adj(n) ;
        for(auto &e : edges){
            int u = e[0] , v = e[1] , w = e[2] ;
            --u , --v ;
            adj[u].push_back({v,w}) ;
            adj[v].push_back({u,w}) ;
        }
        vector<int> dist = dijkstras(adj) ;
        return dfs(adj,dist,0) ;
    }
};