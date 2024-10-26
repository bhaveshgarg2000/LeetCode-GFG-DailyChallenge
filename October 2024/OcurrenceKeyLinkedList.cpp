class Solution
{
public:
    int count(struct Node *head, int key)
    {
        struct Node *curr = head;
        int count = 0;
        while (curr != NULL)
        {
            if (curr->data == key)
            {
                count++;
            }
            curr = curr->next;
        }
        return count;
    }
};