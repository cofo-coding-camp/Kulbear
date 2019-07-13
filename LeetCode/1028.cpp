
class Solution
{
public:
    TreeNode *recoverFromPreorder(string S)
    {
        int progress = 0;
        return recoverNode(S, progress, 0);
    }

private:
    TreeNode *recoverNode(string &s, int &idx, int depth)
    {
        // compute depth of current val
        int d = 0;
        while (idx < s.length() && s[idx] == '-')
        {
            idx++;
            d++;
        }
        // illegal node: means here we get a None node
        // also means the node with this value is a child of another node
        if (d != depth)
        {
            idx -= d;
            return nullptr;
        }

        // compute node value
        int val = 0;
        while (idx < s.length() && isdigit(s[idx]))
        {
            val = val * 10 + (s[idx++] - '0');
        }

        // recursive calls
        TreeNode *root = new TreeNode(val);
        root->left = recoverNode(s, idx, d + 1);
        root->right = recoverNode(s, idx, d + 1);
        return root;
    }
};