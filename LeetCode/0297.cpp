/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        ostringstream o;
        serialize(root, o);
        return o.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream i(data);
        return deserialize(i);
    }

private:
    void serialize(TreeNode *root, ostringstream &o)
    {
        if (!root)
        {
            o << "# ";
            return;
        }
        o << root->val << " ";
        serialize(root->left, o);
        serialize(root->right, o);
    }

    TreeNode *deserialize(istringstream &i)
    {
        string val;
        i >> val;
        if (val == "#")
        {
            return nullptr;
        }
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(i);
        root->right = deserialize(i);

        return root;
    }
};