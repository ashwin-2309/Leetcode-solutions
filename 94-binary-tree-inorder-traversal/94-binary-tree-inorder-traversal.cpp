/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void morris(TreeNode* root,vector<int>&res)
    {
        TreeNode* cur = root;
        while(cur){
            if(cur->left == NULL)
            {
                res.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode* prev = cur->left;
                while(prev->right and prev->right != cur)
                {
                    prev = prev->right;
                }
                //case 1
                if(prev->right == NULL)
                {
                    prev->right = cur;
                    cur = cur->left;
                }
                else if(prev->right == cur)
                {
                    prev->right = NULL;
                    //visited the root again
                    res.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        morris(root,res);
        return res;
    }
};