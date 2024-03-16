class Solution
{
public:
    // Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del_node)
    {
        // Your code here
        if (del_node->next == NULL)
        {
            return;
        }
        Node *prev = del_node;
        Node *curr = del_node->next;
        Node *next_next = del_node->next->next;
        //   data copy
        prev->data = curr->data;
        //   prev -> next changed
        prev->next = next_next;
        // delete of node
        delete curr;
        return;
    }
};