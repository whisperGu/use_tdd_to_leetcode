给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 
给定如下二叉树，以及目标和 sum = 22，

              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/path-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

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
  bool DFS(TreeNode* root, int sum){
        if(root == NULL){
            return false;
        }
        if(!root->left &&!root->right){
            if(root->val == sum){
                return true;
            }
        }
        return (DFS(root->left, sum-root->val) || DFS(root->right, sum -root->val));
    }
    bool hasPathSum(TreeNode* root, int sum) {
        return DFS(root, sum);
    }

};