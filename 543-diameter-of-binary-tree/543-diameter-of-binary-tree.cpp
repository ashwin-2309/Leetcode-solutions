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
    //total of 3 methods
    //method 1 height and diameter in separate O(N^2)
    int height(TreeNode* node)
    {
        //this is expecting edges instead of nodes so final answer -1;
        if(node == NULL)return 0;
        int lh = height(node->left);
        int rh = height(node->right);
        return 1+max(lh,rh);
        
    }
    int diameter0(TreeNode* node)
    {
        if(node == NULL)return 0;
        int ld = diameter0(node->left);
        int rd = diameter0(node->right);
        int lh = height(node->left);
        int rh = height(node->right);
        int myDia = lh+rh+1;
        int mx = max({ld,rd,myDia});
        return mx;
    }
    //--------------------------------------------------- 
    //method 2 using pair and storing diameter in first and height in second
    pair<int,int> diameter1(TreeNode* node)
    {
        if(node == NULL)return {0,0};
        pair<int,int> left = diameter1(node->left);
        pair<int,int> right = diameter1(node->right);
        
        int ld = left.first;
        int rd = right.first;
        int lh = left.second;
        int rh = right.second;
        int myDia = lh+rh+1;
        int d =  max({ld,rd,myDia});
        int height = max(lh,rh)+1;
        pair<int,int> p = make_pair(d,height);
        return p;
    }
    
    //method 3 using a thing which stores max diameter
    int diameter2(TreeNode* node,int &mx)
    {
        //this is height basically
        //concept is that we are basically at every node calculating left height and right height and adding 1
        //so the diameter passes through that node
        if(node == NULL)return 0;
        int lh = diameter2(node->left,mx);
        int rh = diameter2(node->right,mx);
        mx = max(mx,lh+rh+1);
        return max(lh,rh)+1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;
        // int ans = diameter0(root);
        // int ans = diameter1(root).first;
        int mx = 0;
        diameter2(root,mx);
        return mx-1;
        // return ans-1;
    }
};





