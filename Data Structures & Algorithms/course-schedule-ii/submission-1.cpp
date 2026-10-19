class Solution {
    bool hasCycle(int node, vector<vector<int>>& graph, vector<int>& state, vector<int>& res){
        if(state[node] == 1) return true;
        if(state[node] == 2) return false;

        state[node] = 1;

        for(int neighbor: graph[node]){
            if(hasCycle(neighbor, graph, state, res)){
                return true;
            }
        }
        state[node] = 2;
        res.push_back(node);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& preReq : prerequisites){
            graph[preReq[1]].push_back(preReq[0]);
        }

        vector<int> state(numCourses, 0);
        vector<int> res;

        for(int i = 0; i < numCourses; i++){
            if(state[i] == 0){
                if(hasCycle(i, graph, state, res)){
                    return {};
                }
            }
        }

        reverse(res.begin(), res.end());

        return res;
    }
};
