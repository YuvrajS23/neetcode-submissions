class Solution {
    bool hasCycle(int node, vector<vector<int>>& graph, vector<int>& state){
        if(state[node] == 1) return true;
        if(state[node] == 2) return false;

        state[node] = 1;

        for(int neighbor : graph[node]){
            if(hasCycle(neighbor, graph, state)){
                return true;
            }
        }

        state[node] = 2;

        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& preReq : prerequisites){
            graph[preReq[1]].push_back(preReq[0]);
        }

        vector<int> state(numCourses, 0);

        for(int i = 0; i < numCourses; i++){
            if(state[i] == 0){
                if(hasCycle(i, graph, state)){
                    return false;
                }
            }
        }

        return true;
    }
};
