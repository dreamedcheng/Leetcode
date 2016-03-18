class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        if (numCourses == 0)
            return true;
        
        unordered_map<int, vector<int>> topo;
        vector<int> in_degree(numCourses, 0);
        int n = prerequisites.size();
        
        for (int i = 0; i < numCourses; i++) {
            vector<int> tmp;
            topo[i] = tmp;
        }
        
        for (int i = 0; i < n; i++) {
            topo[prerequisites[i].second].push_back(prerequisites[i].first);
            in_degree[prerequisites[i].first] ++;
        }
        
        int flag = 1, num = 0;
        vector<bool> visited(numCourses, false);
        
        while (flag) {
            flag = 0;
            num = 0;
            for (int i = 0; i < numCourses; i++) {
                if (visited[i]) {
                    num++;
                    continue;
                }
                if (in_degree[i] == 0) {
                    for (int j = 0; j < topo[i].size(); j++) {
                        in_degree[topo[i][j]]--;
                    }
                    visited[i] = true;
                    flag = 1;
                }
            }
        }
        
        if (num == numCourses)
            return true;
        
        return false;
    }
};
