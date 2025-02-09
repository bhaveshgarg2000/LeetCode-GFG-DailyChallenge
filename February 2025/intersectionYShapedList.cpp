Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    if (firstHead == NULL || secondHead == NULL)
    {
        return NULL;
    }
    Node *t1 = firstHead;
    Node *t2 = secondHead;
    while (t1 != t2)
    {
        t1 = t1->next;
        t2 = t2->next;

        if (t1 == t2)
        {
            return t2;
        }

        if (t1 == NULL)
        {
            t1 = secondHead;
        }
        if (t2 == NULL)
        {
            t2 = firstHead;
        }
    }

    return t2;
}