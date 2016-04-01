class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        int flag = 0;
        vector<int> ans;
        vector<int> used;
        unordered_map<int, int> in_degree;
        unordered_map<int, vector<int> > out_edges;
        
        
        if (numCourses == 0)
            return ans;
        
        if (prerequisites.size() == 0) {
            for (int i = 0; i < numCourses; i++) {
                ans.push_back(i);
            }
            
            return ans;
        }
            
        for (int i = 0; i < numCourses; i++)
            in_degree[i] = 0;
            
        for (int i = 0; i < prerequisites.size(); i++) {
            int pre = prerequisites[i].second;
            int post = prerequisites[i].first;
            
            in_degree[post] ++;
            if (out_edges.find(pre) == out_edges.end()) {
                vector<int> vec;
                vec.push_back(post);
                out_edges[pre] = vec;
            }
            else {
                out_edges[pre].push_back(post);
            }
            
        }
        
        
        while (ans.size() != numCourses) {
            for (auto i = in_degree.begin(); i != in_degree.end(); i++) {
                if ((i) -> second == 0) {
                    ans.push_back((i) -> first);
                    for (int j = 0; j < out_edges[i->first].size(); j++) {
                        int id = out_edges[i->first][j];
                        in_degree[id]--;
                    }
                    
                    used.push_back((i) -> first);
                    flag = 1;
                }
            }
            
            if (flag == 0) {
                ans.clear();
                return ans;
            }
            
            flag = 0;
            
            for (int i = 0; i < used.size(); i++)
                in_degree.erase(used[i]);
            used.clear();
        }
        
            
    }
};
