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
    vector<int> inorderTraversal(TreeNode* root) {
        // Create a stack to store the nodes that have not been visited yet
        stack<TreeNode*> st;
        // Set the current node to the root
        TreeNode* node = root;
        // Create a vector to store the inorder traversal
        vector<int> ans;

        // Keep iterating until we have visited all nodes
        while(1) {
            // If the current node is not null, push it onto the stack
            // and set the current node to its left child
            if(node != NULL) {
                st.push(node);
                node = node->left;
            }
            // If the current node is null, it means we have reached the
            // leftmost leaf of the tree.
            else {
                // If the stack is empty, we have finished traversing the tree
                // and we can break out of the loop
                if(st.empty() == true) {
                    break;
                }
                // Pop the top element off the stack and add its value to the result vector
                node = st.top();
                st.pop();
                ans.push_back(node->val);
                // Set the current node to the right child of the popped node
                // and continue the process
                node = node->right;
            }
        }
        // Return the inorder traversal of the tree
        return ans;
    }
};
