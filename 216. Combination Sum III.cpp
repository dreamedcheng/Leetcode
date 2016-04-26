class Solution {
public:
    void dfs_combine(vector<vector<int>>& ans, vector<int>& tmp, int k, int n, int cur, int sum, int depth) {
        //if (sum + (9 + 9 - k + depth)*(k-depth)/2 < n || sum + k * (k - depth) > n)
          //  return;
        
        if (depth == k) {
            if (sum == n) {
                ans.push_back(tmp);
            }
            return;
        }
        
        for (int i = cur; i < 10; i++) {
            tmp.push_back(i);
            dfs_combine(ans, tmp, k, n, i+1, sum+i, depth+1);
            tmp.pop_back();
        }
        
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        
        dfs_combine(ans, tmp, k, n, 1, 0, 0);
        
        return ans;
    }
};
