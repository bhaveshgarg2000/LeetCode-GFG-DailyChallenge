class Solution
{
public:
    // Helper function to convert binary tree to doubly linked list
    void bToDLLHelper(Node *root, Node *&prev, Node *&head)
    {
        if (root == NULL)
        {
            return;
        }

        // Recursively convert left subtree
        bToDLLHelper(root->left, prev, head);

        // Process the current node
        if (prev == NULL)
        {
            // If this is the leftmost node, set it as head
            head = root;
        }
        else
        {
            // Link the current node with the previous node in the list
            root->left = prev;
            prev->right = root;
        }

        // Update the previous node
        prev = root;

        // Recursively convert right subtree
        bToDLLHelper(root->right, prev, head);
    }

    // Main function to convert binary tree to doubly linked list
    Node *bToDLL(Node *root)
    {
        Node *prev = NULL;
        Node *head = NULL;
        bToDLLHelper(root, prev, head);
        return head;
    }
};
