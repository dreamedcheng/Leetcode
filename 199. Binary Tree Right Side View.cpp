/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;
            
        vector<TreeNode*> cur;
        vector<TreeNode*> next;
        
        cur.push_back(root);
        
        while(!cur.empty()) {
            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] -> left != NULL)
                    next.push_back(cur[i]->left);
                if (cur[i] -> right != NULL)
                    next.push_back(cur[i]->right);
            }
            
            ans.push_back(cur[cur.size()-1]->val);
            cur.swap(next);
            next.clear();
        }
        
        return ans;
    }
};
