
1110. 删点成林
难度
中等

22





给出二叉树的根节点 root，树上每个节点都有一个不同的值。
如果节点值在 to_delete 中出现，我们就把该节点从树上删去，最后得到一个森林（一些不相交的树构成的集合）。
返回森林中的每棵树。你可以按任意顺序组织答案。
 
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
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
    vector<TreeNode*> helper(TreeNode** root, const set<int>& s) {
        if (*root == NULL) return {};
        auto lnodes = helper(&(*root)->left, s);
        auto rnodes = helper(&(*root)->right, s);
        if (s.count((*root)->val)) {
            *root = NULL;
            lnodes.insert(lnodes.end(), rnodes.begin(), rnodes.end());
            return lnodes;
        }
        if (!lnodes.empty() && lnodes.back() == ((*root)->left)) lnodes.pop_back();
        if (!rnodes.empty() && rnodes.back() == ((*root)->right)) rnodes.pop_back();
        lnodes.insert(lnodes.end(), rnodes.begin(), rnodes.end());
        lnodes.push_back(*root);
        return lnodes;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        set<int> s(to_delete.begin(), to_delete.end());
        return helper(&root, s);
    }
};
