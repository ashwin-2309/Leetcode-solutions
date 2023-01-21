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
    vector<int> morris(TreeNode* root)
    {
        vector<int> preorder;
        TreeNode* node = root;
        while(node != NULL)
        {
            if(node->left == NULL)
            {
                //push the value and go to the right
                preorder.push_back(node->val);
                node = node->right;
            }
            else{
                //we have to make the thread ie join the inorder predecessor to the node
                TreeNode* prev = node->left;
                while(prev->right != NULL and prev->right!= node)
                {
                    prev = prev->right;
                }
                
                //case 1
                if(prev->right == NULL)
                {
                    //making the thread
                    prev->right = node;
                    preorder.push_back(node->val);
                    node=node->left;
                }
                else if(prev->right == node){
                    //thread already made
                    prev->right = NULL;
                    
                    node=node->right;
                }
            }
        }
        return preorder;
    }
    vector<int> iterative(TreeNode* root)
    {
        //iterative preorder
        stack<TreeNode*> st;
        if(root == NULL)return {};
        st.push(root);
        vector<int> ans;
        
        while(!st.empty())
        {
            auto temp = st.top();
            st.pop();
            ans.push_back(temp->val);
            if(temp->right)st.push(temp->right);
            if(temp->left)st.push(temp->left);
            
            
        }
        return ans;
    }
    vector<int> preorderTraversal(TreeNode* root) {
        return morris(root);
    }
};