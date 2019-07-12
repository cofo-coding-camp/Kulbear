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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return buildBT(nums, 0, nums.size());
    }

private:
    TreeNode *buildBT(vector<int> &nums, int s, int e)
    {
        if (s >= e)
        {
            return nullptr;
        }
        auto it = std::max_element(nums.begin() + s, nums.begin() + e);
        TreeNode *root = new TreeNode(*it);
        int index = it - nums.begin();
        root->left = buildBT(nums, s, index);
        root->right = buildBT(nums, index + 1, e);
        return root;
    }
};