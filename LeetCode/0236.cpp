/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        unordered_map<TreeNode *, TreeNode *> parents;
        stack<TreeNode *> s;
        if (!root)
        {
            return root;
        }
        s.push(root);

        // build the parent-child relation map
        while (s.size())
        {
            TreeNode *cur = s.top();
            s.pop();
            if (cur->left)
            {
                parents.emplace(cur->left, cur);
                s.push(cur->left);
            }
            if (cur->right)
            {
                parents.emplace(cur->right, cur);
                s.push(cur->right);
            }
        }

        set<TreeNode *> anc;
        // track all ancestors start with p
        while (p)
        {
            anc.emplace(p);
            p = parents[p];
        }

        // the first node start from q found in `anc` is the answer
        while (anc.find(q) == anc.end())
        {
            q = parents[q];
        }
        return q;
    }
};