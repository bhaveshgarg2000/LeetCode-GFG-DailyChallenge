class Solution
{
public:
    Node *RemoveHalfNodes(Node *root)
    {
        // when root node is null : empty tree

        // INODER TRAVERSAL
        if (root == NULL)
        {
            return NULL;
        }

        // left call of tree
        root->left = RemoveHalfNodes(root->left);
        // left call of tree
        root->right = RemoveHalfNodes(root->right);

        // when root reaches to end of tree (end of child)
        if (root->left == NULL && root->right == NULL)
        {
            return root;
        }

        // when left children is not there of node
        if (root->left == NULL)
        {
            // new node pointing to root->right
            Node *new_node = root->right;
            // free current root
            free(root);
            // return right child
            return new_node;
        }

        // when right children is not there of node
        if (root->right == NULL)
        {
            // new node pointing to root->left
            Node *new_node = root->left;
            // free current root
            free(root);
            // return right child
            return new_node;
        }

        return root;
    }
};