class Solution
{
public:
    Node *reverse(Node *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        Node *temp = head;
        Node *newHead = reverse(head->next);
        temp->next->next = temp;
        temp->next = NULL;
        return newHead;
    }

    int len(Node *head)
    {
        Node *temp = head;
        int count = 0;
        while (temp)
        {
            temp = temp->next;
            count++;
        }
        return count;
    }

    Node *big(Node *h1, Node *h2)
    {
        Node *temp = h1;
        Node *temp2 = h2;
        while (temp && temp2)
        {
            if (temp->data == temp2->data)
            {
                temp = temp->next;
                temp2 = temp2->next;
            }
            else if (temp->data > temp2->data)
            {
                return h1;
            }
            else
            {
                return h2;
            }
        }
        return h1;
    }

    int sub(int a, int b, int &borrow)
    {
        if (borrow)
        {
            borrow = 0;
            a = sub(a, 1, borrow);
        }
        if (a >= b)
        {
            return a - b;
        }
        borrow = 1;
        return 10 + a - b;
    }

    Node *subList(Node *h1, Node *h2)
    {
        Node *temp = h1;
        Node *temp2 = h2;
        Node *result = new Node(0);
        Node *ans = result;
        int borrow = 0;
        while (temp2)
        {
            int res = sub(temp->data, temp2->data, borrow);
            // cout<<"res->"<<res<<endl;
            Node *add = new Node(res);
            ans->next = add;
            temp = temp->next;
            temp2 = temp2->next;
            ans = ans->next;
        }
        while (temp)
        {
            if (borrow)
            {
                temp->data = sub(temp->data, 0, borrow);
            }
            ans->next = temp;
            temp = temp->next;
            ans = ans->next;
        }

        return result->next;
    }

    Node *Zero(Node *head)
    {
        if (head->next == NULL)
        {
            return head;
        }
        Node *temp = head;
        while (temp && temp->data == 0)
        {
            if (!temp->next)
            {
                return temp;
            }
            temp = temp->next;
        }
        return temp;
    }

    Node *subLinkedList(Node *head1, Node *head2)
    {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        Node *h1 = Zero(head1);
        Node *h2 = Zero(head2);
        int m = len(h1);
        int n = len(h2);
        if (m > n)
        {
            return Zero(reverse(subList(reverse(h1), reverse(h2))));
        }
        else if (n > m)
        {
            return Zero(reverse(subList(reverse(h2), reverse(h1))));
        }
        Node *first = big(h1, h2);
        if (first == h1)
        {
            return Zero(reverse(subList(reverse(h1), reverse(h2))));
        }
        else
        {
            return Zero(reverse(subList(reverse(h2), reverse(h1))));
        }
        return NULL;
    }