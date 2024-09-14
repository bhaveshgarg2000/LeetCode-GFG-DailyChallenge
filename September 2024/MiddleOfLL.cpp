class Solution
{
public:
    int getMiddle(Node *head)
    {
        Node *Fast = head;
        Node *Slow = head;
        while (Fast && Fast->next)
        {
            Fast = Fast->next->next;
            Slow = Slow->next;
        }
        return Slow->data;
    }
};