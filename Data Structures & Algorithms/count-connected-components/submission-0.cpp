class Solution {
    void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int source){
        if(visited[node]) return;

        visited[node] = true;

        for(auto& neighbor : graph[node]){
            if(neighbor != source){
                dfs(neighbor, graph, visited, node);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& edge:edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int res = 0;

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, graph, visited, -1);
                res++;
            }
        }

        return res;
    }
};
