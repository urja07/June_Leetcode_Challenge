class Solution {
    void dfs(unordered_map<string, multiset<string>>& adj, vector<string>& res, string s){
        while(adj[s].size()){
            string s1= *(adj[s].begin());
            adj[s].erase(adj[s].begin());
            dfs(adj, res, s1);
        }
        res.push_back(s);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, multiset<string>> adj;
        for(auto i: tickets){
            adj[i[0]].insert(i[1]);
        }
        vector<string> res;
        dfs(adj,res,"JFK");
        reverse(res.begin(),res.end());
        return res;
    }
};
