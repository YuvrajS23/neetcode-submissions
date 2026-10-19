class Solution {
    bool hasCycle(int node,vector<vector<int>>& graph, vector<int>& state, int source){
        if(state[node] == 1) return true;
        if(state[node] == 2) return false;

        state[node] = 1;

        for(int neighbor: graph[node]){
            if(neighbor != source){
                if(hasCycle(neighbor, graph, state, node)){
                    return true;
                }
            }
        }
        state[node] = 2;
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto& edge: edges){
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> state(n, 0);
        int components = 0;

        for(int i = 0; i < n; i++){
            if(state[i] == 0){
                if(hasCycle(i, graph, state, -1)){
                    return false;
                }
                components++;
            }
        }

        return (components > 1) ? false : true;
    }
};
