class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indegree(n+1, 0);
        vector<vector<int>> adj(n+1, vector<int>());
        for(auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }

        queue<int> q;
        for(int i = 1; i <= n; i++){
            if(indegree[i] == 1){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            indegree[node]--;
            q.pop();
            for(auto& neigh : adj[node]){
                indegree[neigh]--;
                if(indegree[neigh] == 1) q.push(neigh);
            }
        }

        for(int i = n-1; i >= 0; i--){
            if(indegree[edges[i][0]] == 2 && indegree[edges[i][1]]){
                return edges[i];
            }
        }

        return {};
    }
};
