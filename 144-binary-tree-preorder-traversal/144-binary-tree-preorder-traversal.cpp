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
   vector<int> morris(TreeNode* root) {
    vector<int> preorder;
    TreeNode* current = root; 

    while (current != NULL) {
        if (current->left == NULL) {
            // If there's no left child, add the current node's value to the preorder vector and move to the right
            preorder.push_back(current->val);
            current = current->right;
        } else {
            // Find the inorder predecessor (rightmost node in left subtree)
            TreeNode* inorder_predecessor = current->left;
            while (inorder_predecessor->right != NULL && inorder_predecessor->right != current) {
                inorder_predecessor = inorder_predecessor->right;
            }

            // If there's no thread between the inorder predecessor and the current node
            if (inorder_predecessor->right == NULL) {
                // Create a thread and add the current node's value to the preorder vector
                inorder_predecessor->right = current;
                preorder.push_back(current->val);
                current = current->left;
            }
            // If there's already a thread between the inorder predecessor and the current node
            else {
                // Break the thread and move to the right
                inorder_predecessor->right = NULL;
                current = current->right;
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