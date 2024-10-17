class Solution
{
public:
    vector<Node *> alternatingSplitList(struct Node *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return {head, NULL};
        }
        Node *first = head;
        Node *second = head->next;
        Node *odd = first;
        Node *even = second;

        while (odd != NULL && even != NULL && odd->next != NULL && even->next != NULL)
        {

            odd->next = even->next;
            odd = odd->next;

            if (odd != NULL)
            {
                even->next = odd->next;
                even = even->next;
            }
        }

        if (odd != NULL)
            odd->next = NULL;
        if (even != NULL)
            even->next = NULL;

        return {first, second};
    }
};