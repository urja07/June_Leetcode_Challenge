class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<vector<pair<int,int>>> adj(n);
        
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        priority_queue<vector<int> , vector<vector<int>> , greater<vector<int>>> q;
        q.push({0,src,K+1});
        while(!q.empty()){
            vector<int> top =q.top();
            q.pop();
            int d = top[0];
            int u = top[1];
            int e = top[2];
            if(dst==u)
                return d;
            if(e>0){
                for( auto i: adj[u])
                    q.push({d+i.second, i.first, e-1});
            }
        }
        return -1;
        
    }
};
